/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104


Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <cassert>
#include <vector>
#include <limits>
#include <algorithm>

int max_sub_array(std::vector<int> &nums)
{
    int ans = std::numeric_limits<int>::min();
    int sum = 0;
    for (const int num : nums)
    {
        sum = std::max(num, sum + num);
        ans = std::max(ans, sum);
    }
    return ans;
}

int main(int argc, char **argv)
{
    std::vector a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(max_sub_array(a) == 6); // sum of [4,-1,2,1] is 6
    std::vector b{1};
    assert(max_sub_array(b) == 1);
    std::vector c{5,4,-1,7,8};
    assert(max_sub_array(c) == 23);
    return 0;
}