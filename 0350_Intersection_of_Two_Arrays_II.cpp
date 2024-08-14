/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> intersection;
    std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(intersection));
    return intersection;
}

int main(int argc, char **argv)
{
    {
        std::vector<int> a{1,2,2,1};
        std::vector<int> b{2,2};
        std::vector<int> result{2, 2};
        assert(intersect(a, b) == result);
    }
    {
        std::vector<int> a{4,9,5};
        std::vector<int> b{9,4,9,8,4};
        std::vector<int> result{4, 9};
        assert(intersect(a, b) == result);
    }
    return 0;
}
