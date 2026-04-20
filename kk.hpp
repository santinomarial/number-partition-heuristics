#pragma once
#include <vector>
#include <cstdint>

// Karmarkar-Karp deterministic heuristic.
// Returns the residue (|sum_A - sum_B|) of the partition it finds.
int64_t karmarkar_karp(std::vector<int64_t> nums);
