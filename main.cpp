#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "heuristics.hpp"
#include "kk.hpp"
#include "prepartition.hpp"

static constexpr int ITERATIONS = 25000;

static std::vector<int64_t> read_input(const std::string& path) {
    std::ifstream f(path);
    if (!f) {
        std::cerr << "error: cannot open " << path << "\n";
        std::exit(1);
    }
    std::vector<int64_t> nums;
    nums.reserve(100);
    int64_t x;
    while (f >> x) nums.push_back(x);
    return nums;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "usage: " << argv[0] << " <flag> <algorithm> <inputfile>\n";
        return 1;
    }

    int flag      = std::stoi(argv[1]);
    int algorithm = std::stoi(argv[2]);
    std::string inputfile = argv[3];

    (void)flag; // reserved for debug / extension modes

    std::vector<int64_t> nums = read_input(inputfile);

    int64_t residue = 0;

    switch (algorithm) {
        case 0:  residue = karmarkar_karp(nums);              break;
        case 1:  residue = repeated_random(nums, ITERATIONS); break;
        case 2:  residue = hill_climbing(nums, ITERATIONS);   break;
        case 3:  residue = simulated_annealing(nums, ITERATIONS); break;
        case 11: residue = pp_repeated_random(nums, ITERATIONS);  break;
        case 12: residue = pp_hill_climbing(nums, ITERATIONS);    break;
        case 13: residue = pp_simulated_annealing(nums, ITERATIONS); break;
        default:
            std::cerr << "error: unknown algorithm " << algorithm << "\n";
            return 1;
    }

    std::cout << residue << "\n";
    return 0;
}
