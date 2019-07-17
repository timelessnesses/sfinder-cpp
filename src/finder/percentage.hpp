#ifndef FINDER_PERCENTAGE_HPP
#define FINDER_PERCENTAGE_HPP

#include "../core/moves.hpp"
#include "perfect_clear/finder.hpp"
#include "permutations.hpp"
#include "spins.hpp"
#include "lookup.hpp"

namespace finder {
    template<class T = core::srs::MoveGenerator>
    class Percentage {
    public:
        explicit Percentage(
                perfect_clear::Finder<T> &finder,
                const Permutations &permutations,
                const ReverseLookup &reverseLookup
        ) : finder_(finder), permutations_(permutations), reverseLookup_(reverseLookup) {}

        int run(const core::Field &field, int maxDepth, int maxLine);

    private:
        perfect_clear::Finder<T> &finder_;
        const Permutations &permutations_;
        const ReverseLookup &reverseLookup_;
    };
}

#endif //FINDER_PERCENTAGE_HPP
