#pragma once
#include <vector>
#include <cstdint>

// Algorithms 11–13 operate on the prepartition representation:
// a mapping p : {0..n-1} -> {0..n-1} induces a transformed instance
// a'[j] = sum of a[i] for all i where p[i]==j, then KK is run on a'.

// Algorithm 11: Repeated Random on prepartition representation.
int64_t pp_repeated_random(const std::vector<int64_t>& nums, int iterations);

// Algorithm 12: Hill Climbing on prepartition representation.
int64_t pp_hill_climbing(const std::vector<int64_t>& nums, int iterations);

// Algorithm 13: Simulated Annealing on prepartition representation.
int64_t pp_simulated_annealing(const std::vector<int64_t>& nums, int iterations);
