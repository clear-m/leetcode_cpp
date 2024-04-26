#include <algorithm>
#include <vector>
#include <cassert>

void rotate(std::vector<int> &nums, int k)
{
    if (nums.empty())
    {
        return;
    }
    // normalize
    k = k % nums.size();
    std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
}

int main(int argc, char** argv)
{
    std::vector<int> a{0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9};
    const std::vector<int> b{9, 0, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8};
    const std::vector<int> c{7, 8, 9, 0, 1, 2, 3, 3, 4, 4, 5, 6};
    rotate(a, 1);
    assert(a == b);
    rotate(a, 2);
    assert(a == c);
    return 0;
}
