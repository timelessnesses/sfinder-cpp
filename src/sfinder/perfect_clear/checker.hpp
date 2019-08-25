#ifndef FINDER_PERFECT_CLEAR_CHECKER_HPP
#define FINDER_PERFECT_CLEAR_CHECKER_HPP

#include "../types.hpp"
#include "../spins.hpp"
#include "../../core/factory.hpp"
#include "../../core/moves.hpp"
#include "full_finder.hpp"

namespace sfinder::perfect_clear {
    namespace {
        struct Candidate2 {
            const core::Field field;
            const int currentIndex;
            const int holdIndex;
            const int leftLine;
            const int depth;
        };

        struct Configure2 {
            const std::vector<core::PieceType> &pieces;
            std::vector<std::vector<core::Move>> &movePool;
            const int maxDepth;
            const int pieceSize;
        };
    }

    template<class T = core::srs::MoveGenerator>
    class Checker {
    public:
        Checker<T>(const core::Factory &factory, T &moveGenerator) :
                factory_(factory), moveGenerator_(moveGenerator),
                reachable_(core::srs_rotate_end::Reachable(factory)) {
        }

        template<bool UseFirstHold>
        bool run(
                const core::Field &field, const std::vector<core::PieceType> &pieces,
                int maxDepth, int maxLine, bool holdEmpty
        ) {
            assert(1 <= maxDepth && maxDepth <= pieces.size());

            if (!validate(field, maxLine)) {
                return false;
            }

            // Copy field
            auto freeze = core::Field(field);

            // Initialize moves
            std::vector<std::vector<core::Move>> movePool(maxDepth);
            for (int index = 0; index < maxDepth; ++index) {
                movePool[index] = std::vector<core::Move>{};
            }

            // Initialize configure
            const Configure2 configure{
                    pieces,
                    movePool,
                    maxDepth,
                    static_cast<int>(pieces.size()),
            };

            // Create candidate
            auto candidate = holdEmpty ? Candidate2{
                    freeze, 0, -1, maxLine, 0,
            } : Candidate2{
                    freeze, 1, 0, maxLine, 0,
            };

            // Execute
            return search<UseFirstHold>(configure, candidate);
        }

    private:
        const core::Factory &factory_;
        T &moveGenerator_;
        core::srs_rotate_end::Reachable reachable_;

        // UseFirstHold = false if do not allow hold at first call only
        template<bool UseFirstHold>
        bool search(
                const Configure2 &configure,
                const Candidate2 &candidate
        ) {
            auto depth = candidate.depth;

            auto &pieces = configure.pieces;
            auto &moves = configure.movePool[depth];

            auto currentIndex = candidate.currentIndex;
            assert(0 <= currentIndex && currentIndex <= configure.pieceSize);
            auto holdIndex = candidate.holdIndex;
            assert(-1 <= holdIndex && holdIndex < static_cast<long long int>(configure.pieceSize));

            bool canUseCurrent = currentIndex < configure.pieceSize;
            if (canUseCurrent) {
                assert(static_cast<unsigned int>(currentIndex) < pieces.size());
                auto &current = pieces[currentIndex];

                moves.clear();
                if (move(configure, candidate, moves, current, currentIndex + 1, holdIndex)) {
                    return true;
                }
            }

            if constexpr (UseFirstHold) {
                if (0 <= holdIndex) {
                    assert(static_cast<unsigned int>(holdIndex) < pieces.size());

                    // Hold exists
                    if (!canUseCurrent || pieces[currentIndex] != pieces[holdIndex]) {
                        auto &hold = pieces[holdIndex];

                        moves.clear();
                        if (move(configure, candidate, moves, hold, currentIndex + 1, currentIndex)) {
                            return true;
                        }
                    }
                } else {
                    assert(canUseCurrent);

                    // Empty hold
                    auto nextIndex = currentIndex + 1;
                    assert(static_cast<unsigned int>(nextIndex) < pieces.size() + 1);

                    if (nextIndex < configure.pieceSize && pieces[currentIndex] != pieces[nextIndex]) {
                        assert(static_cast<unsigned int>(nextIndex) < pieces.size());
                        auto &next = pieces[nextIndex];

                        moves.clear();
                        if (move(configure, candidate, moves, next, nextIndex + 1, currentIndex)) {
                            return true;
                        }
                    }
                }
            }

            return false;
        }

        bool move(
                const Configure2 &configure,
                const Candidate2 &candidate,
                std::vector<core::Move> &moves,
                core::PieceType pieceType,
                int nextIndex,
                int nextHoldIndex
        ) {
            auto depth = candidate.depth;
            auto maxDepth = configure.maxDepth;
            auto &field = candidate.field;

            auto leftLine = candidate.leftLine;
            assert(0 < leftLine);

            moveGenerator_.search(moves, field, pieceType, leftLine);

            for (const auto &move : moves) {
                auto &blocks = factory_.get(pieceType, move.rotateType);

                auto freeze = core::Field(field);
                freeze.put(blocks, move.x, move.y);

                int numCleared = freeze.clearLineReturnNum();

                int nextLeftLine = leftLine - numCleared;
                if (nextLeftLine == 0) {
                    return true;
                }

                auto nextDepth = depth + 1;
                if (maxDepth <= nextDepth) {
                    continue;
                }

                if (!validate(freeze, nextLeftLine)) {
                    continue;
                }

                auto nextCandidate = Candidate2{
                        freeze, nextIndex, nextHoldIndex, nextLeftLine, nextDepth,
                };

                if (search<true>(configure, nextCandidate)) {
                    return true;
                }
            }

            return false;
        }
    };
}

#endif //FINDER_PERFECT_CLEAR_CHECKER_HPP
