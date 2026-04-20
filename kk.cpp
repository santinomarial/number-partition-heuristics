#include "kk.hpp"
#include <queue>
#include <cstdlib>

int64_t karmarkar_karp(std::vector<int64_t> nums) {
    if (nums.empty()) return 0;
    std::priority_queue<int64_t> heap(nums.begin(), nums.end());
    while (heap.size() > 1) {
        int64_t a = heap.top(); heap.pop();
        int64_t b = heap.top(); heap.pop();
        heap.push(a - b); // a >= b, so difference is non-negative
    }
    return heap.top();
}
