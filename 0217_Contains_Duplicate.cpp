/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true


Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
#include <cassert>
#include <vector>
#include <algorithm>

bool containsDuplicate(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    auto found = std::adjacent_find(nums.begin(), nums.end());
    return found != nums.end();
}

int main(int argc, char **argv)
{
    std::vector a{1,2,3,1};
    std::vector b{1,2,3,4};
    std::vector c{1,1,1,3,3,4,3,2,4,2};
    assert(containsDuplicate(a));
    assert(!containsDuplicate(b));
    assert(containsDuplicate(c));
    return 0;
}
