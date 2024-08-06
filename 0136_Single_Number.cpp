/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
   Hide Hint #1  
Think about the XOR (^) operator's property.
*/
#include <vector>
#include <algorithm>
#include <cassert>

int single_number(std::vector<int>& nums) {
    int target{};
    std::for_each(nums.begin(), nums.end(), [&](const int& num){
        target ^= num;
    });
    return target;
}

int main(int argc, char** argv)
{
    {
        std::vector a{2,2,1};
        assert(single_number(a) == 1);
    }
    {
        std::vector b{4,1,2,1,2};
        assert(single_number(b) == 4);
    }
    return 0;
}
