#pragma once
#include <vector>
#include <cstdint>

// Algorithms 1–3 operate on the standard sign-vector representation
// (each element assigned +1 or -1).

// Algorithm 1: Repeated Random — random sign-vector, keep best residue.
int64_t repeated_random(const std::vector<int64_t>& nums, int iterations);

// Algorithm 2: Hill Climbing — random start, accept neighbor if better.
int64_t hill_climbing(const std::vector<int64_t>& nums, int iterations);

// Algorithm 3: Simulated Annealing — accept worse neighbor with decreasing probability.
int64_t simulated_annealing(const std::vector<int64_t>& nums, int iterations);
