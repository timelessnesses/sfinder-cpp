#ifndef CORE_PERFECT_CLEAR_HPP
#define CORE_PERFECT_CLEAR_HPP

#include "./types.hpp"
#include "../core/factory.hpp"
#include "../core/moves.hpp"

namespace finder {
    enum TSpinShapes {
        NoShape,
        RegularShape,
        MiniOrTSTShape,
    };

    TSpinShapes getTSpinShape(const core::Field &field, int x, int y, core::RotateType rotateType);

    int getAttackIfTSpin(
            core::srs_rotate_end::Reachable &reachable, const core::Factory &factory, const core::Field &field,
            core::PieceType pieceType, const core::Move &move, int numCleared, bool b2b
    );

    int getAttackIfTSpin(
            core::srs_rotate_end::Reachable &reachable, const core::Factory &factory, const core::Field &field,
            core::PieceType pieceType, core::RotateType rotateType, int x, int y, int numCleared, bool b2b
    );

    namespace perfect_clear {
        enum PriorityTypes {
            LeastSoftdrop_LeastLineClear_LeastHold,
            LeastSoftdrop_MostCombo_MostLineClear_LeastHold,
        };

        struct Candidate {
            const core::Field field;
            const int currentIndex;
            const int holdIndex;
            const int leftLine;
            const int depth;
            const int softdropCount;
            const int holdCount;
            const int lineClearCount;
            const int currentCombo;
            const int maxCombo;
            const int tSpinAttack;
            const bool b2b;
            const int leftNumOfT;
        };

        struct Configure {
            const std::vector<core::PieceType> &pieces;
            std::vector<std::vector<core::Move>> &movePool;
            const int maxDepth;
            const int pieceSize;
            const bool leastLineClears;
        };

        struct Record {
            Solution solution;
            int softdropCount;
            int holdCount;
            int lineClearCount;
            int maxCombo;
            int tSpinAttack;
        };

        template<class T = core::srs::MoveGenerator>
        class Finder {
        public:
            Finder<T>(const core::Factory &factory, T &moveGenerator)
                    : factory(factory), moveGenerator(moveGenerator),
                      reachable(core::srs_rotate_end::Reachable(factory)) {
            }

            Solution run(
                    const core::Field &field, const std::vector<core::PieceType> &pieces,
                    int maxDepth, int maxLine, bool holdEmpty
            );

            Solution run(
                    const core::Field &field, const std::vector<core::PieceType> &pieces,
                    int maxDepth, int maxLine, bool holdEmpty, bool leastLineClears, int initCombo
            );

        private:
            const core::Factory &factory;
            T &moveGenerator;
            core::srs_rotate_end::Reachable reachable;
            Record best;

            void search(const Configure &configure, const Candidate &candidate, Solution &solution);

            void move(
                    const Configure &configure,
                    const Candidate &candidate,
                    Solution &solution,
                    std::vector<core::Move> &moves,
                    core::PieceType pieceType,
                    int nextIndex,
                    int nextHoldIndex,
                    int nextHoldCount
            );

            void accept(const Configure &configure, const Record &record);
        };
    }
}

#endif //CORE_PERFECT_CLEAR_HPP
