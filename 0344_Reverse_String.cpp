#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

/*
Time: 𝑂(𝑛)
Space: 𝑂(1)
*/

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
// Constraints:
// 1 <= s.length <= 105
// s[i] is a printable ascii character.
// Hint #1
// The entire logic for reversing a string is based on using the opposite directional two-pointer approach!

void reverseStringReference(std::vector<char> &s)
{
    int l = 0;
    int r = s.size() - 1;
    while (l < r)
    {
        std::swap(s[l++], s[r--]);
    }
}

void reverseString(std::vector<char> &s)
{
    // https://en.cppreference.com/w/cpp/algorithm/reverse
    std::reverse(s.begin(), s.end());
}

int main(int argc, char **argv)
{
    std::vector<char> v1{'h','e','l','l','o'};
    const std::vector<char> v2{'o','l','l','e','h'};
    reverseString(v1);
    assert(v1 == v2);
    std::vector<char> v3{'H','a','n','n','a','h'};
    const std::vector<char> v4{'h','a','n','n','a','H'};
    reverseString(v3);
    assert(v3 == v4);
    return 0;
}
