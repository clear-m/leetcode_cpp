/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.


Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include <algorithm>
#include <string>
#include <map>
#include <cstdint>
#include <vector>
#include <cassert>

#include <type_traits>

template <typename T>
bool is_anagram_any_char(std::basic_string<T> s, std::basic_string<T> t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    std::map<T, std::uint32_t> charset;
    std::for_each(s.begin(), s.end(), [&](auto c)
                  { ++charset[c]; });
    for (const auto c : t)
    {
        if (!charset.contains(c))
        {
            return false;
        }
        if (charset[c] == 0)
        {
            return false;
        }
        --charset[c];
    }
    return true;
}

template <typename T>
concept AnyString = std::is_same_v<std::remove_reference_t<T>, std::u8string> || std::is_same_v<std::remove_reference_t<T>, std::u16string> || std::is_same_v<std::remove_reference_t<T>, std::u32string> || std::is_same_v<std::remove_reference_t<T>, std::wstring> || std::is_same_v<std::remove_reference_t<T>, std::string>;

bool is_anagram_any_string(auto &&s, auto &&t)
    requires std::is_same_v<decltype(s), decltype(t)> && AnyString<decltype(s)>
{
    if (s.length() != t.length())
    {
        return false;
    }
    std::map<std::remove_reference_t<decltype(s[0])>, std::uint32_t> charset;
    std::for_each(s.begin(), s.end(), [&](auto c)
                  { ++charset[c]; });
    for (const auto c : t)
    {
        if (!charset.contains(c))
        {
            return false;
        }
        if (charset[c] == 0)
        {
            return false;
        }
        --charset[c];
    }
    return true;
}

bool is_anagram_ansi(std::string s, std::string t)
{
    if (s.length() != t.length())
        return false;

    std::vector<int> count(26);

    for (const char c : s)
        ++count[c - 'a'];

    for (const char c : t)
    {
        if (count[c - 'a'] == 0)
            return false;
        --count[c - 'a'];
    }
    return true;
}

int main(int argc, char **argv)
{
    {
        assert(is_anagram_any_char<char8_t>(u8"anagram", u8"nagaram"));
        assert(!is_anagram_any_char<char8_t>(u8"rat", u8"car"));
    }
    {
        assert(is_anagram_any_string(std::u16string{u"anagram"}, std::u16string{u"nagaram"}));
        assert(!is_anagram_any_string(std::u32string{U"rat"}, std::u32string{U"car"}));
    }
    return 0;
}
