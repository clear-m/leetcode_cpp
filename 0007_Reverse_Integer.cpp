#include <limits>
#include <cassert>

/*
Time: 𝑂(log 𝑥)
Space: 𝑂(1)
*/

// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Example 1:
// Input: x = 123
// Output: 321
// Example 2:
// Input: x = -123
// Output: -321
// Example 3:
// Input: x = 120
// Output: 21
// Constraints:
// -231 <= x <= 231 - 1

int reverse(int x)
{
    using lim = std::numeric_limits<int>;
    long res{};
    while (x != 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < lim::min() || res > lim::max()) ? 0 : res;
}

int reverseBits(int x)
{
    int i{};
    int j{};
    int t1{};
    int t2{};
    for (i = 0, j = 31; j > i; i++, j--)
    {
        if (t1 != t2)
        {
            // swapping
            x = x ^ (1 << i);
            x = x ^ (1 << j);
        }
    }
    return x;
}

int main(int argc, char **argv)
{
    const int x1 = 123;
    const int x2 = 321;
    assert(reverse(x1) == x2);
    const int x3 = -123;
    const int x4 = -321;
    assert(reverse(x3) == x4);
    const int x5 = 120;
    const int x6 = 21;
    assert(reverse(x5) == x6);
    return 0;
}
