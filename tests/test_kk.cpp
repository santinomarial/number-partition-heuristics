#include "../kk.hpp"
#include <cassert>
#include <cstdio>

int main() {
    assert(karmarkar_karp({10, 8, 7, 6, 5}) == 2);
    assert(karmarkar_karp({1, 2, 3}) == 0);
    assert(karmarkar_karp({42}) == 42);
    assert(karmarkar_karp({}) == 0);
    std::puts("All tests passed.");
    return 0;
}
