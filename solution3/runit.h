#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>

#include "gen.h"
#include "sumsq.h"

template<typename T>
void runit(int len, T initial, T step) {
    // allocate vectors
    std::vector<T> v(len+1), diffs(len+1);

    // fill and randomize v
    std::generate(v.begin(), v.end(), Generator<T>(initial, step));

    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // compute differences
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());

    // compute standard deviation of all differences.
    // Note that the first element is just the original element itself, so we need to skip it.
    const T sum = std::reduce(diffs.begin()+1, diffs.end());
    const T sumsq = std::accumulate(diffs.begin()+1, diffs.end(), T(), sumsquare<T>());

    const T mean = sum/len;
    const T variance = sumsq/len - mean*mean;

    std::cout << "Range = [" << initial << ", " << step*len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << '\n';
}