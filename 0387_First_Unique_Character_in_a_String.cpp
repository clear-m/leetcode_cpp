#include <string>
#include <array>
#include <cassert>

/*
Time: 𝑂(𝑛)
Space: 𝑂(26) = 𝑂(1)
*/

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Example 1:
// Input: s = "leetcode"
// Output: 0
// Example 2:
// Input: s = "loveleetcode"
// Output: 2
// Example 3:
// Input: s = "aabb"
// Output: -1
// Constraints:
// 1 <= s.length <= 105
// s consists of only lowercase English letters.

int firstUniqChar(const std::string &s)
{
    std::array<int, 26> count{0};
    for (const char c : s)
    {
        ++count[c - 'a'];
    }
    for (std::size_t i{0}; i < s.length(); ++i)
    {
        if (count[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("aabb") == -1);
    return 0;
}
