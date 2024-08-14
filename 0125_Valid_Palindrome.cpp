/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <cassert>
#include <string>
#include <cctype>

bool is_palindrome(std::string s)
{
    auto head = s.begin();
    auto tail = s.end();
    tail--;
    while (head < tail)
    {
        if (!std::isalnum(*head))
        {
            head++;
            continue;
        }
        if (!std::isalnum(*tail))
        {
            tail--;
            continue;
        }
        if (std::tolower(*head) != std::tolower(*tail))
        {
            return false;
        }
        head++;
        tail--;
    }
    return true;
}

int main(int argc, char **argv)
{
    assert(is_palindrome("A man, a plan, a canal: Panama"));
    assert(!is_palindrome("race a car"));
    assert(is_palindrome(" "));
    assert(!is_palindrome("0P"));
    return 0;
}
