/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.



Example 1:

Input: n = 27
Output: true
Explanation: 27 = 33
Example 2:

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.
Example 3:

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).


Constraints:

-231 <= n <= 231 - 1


Follow up: Could you solve it without loops/recursion?
*/
#include <cassert>
#include <cmath>

bool is_power_of_three_iter(int n)
{
    while (n > 1 && !(n % 3))
    {
        n = n / 3;
    }
    return n == 1;
}

bool is_power_of_three_smart(int n)
{
    return n > 0 && static_cast<int>(std::pow(3, 19)) % n == 0;
}

int main(int argc, char **argv)
{
    {
        assert(!is_power_of_three_iter(-1));
        assert(!is_power_of_three_iter(0));
        assert(!is_power_of_three_iter(15));
        assert(is_power_of_three_iter(27));
    }
    {
        assert(!is_power_of_three_smart(-1));
        assert(!is_power_of_three_smart(0));
        assert(!is_power_of_three_smart(15));
        assert(is_power_of_three_smart(27));
    }
    return 0;
}
