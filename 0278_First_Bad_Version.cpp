#include <cassert>

/*
Time: 𝑂(log 𝑛)
Space: 𝑂(1)
*/

// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
// You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
// Example 1:
// Input: n = 5, bad = 4
// Output: 4
// Explanation:
// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true
// Then 4 is the first bad version.
// Example 2:
// Input: n = 1, bad = 1
// Output: 1
// Constraints:
// 1 <= bad <= n <= 231 - 1

//INFO: for the test
int test_version{0};

bool isBadVersion(int version)
{
    return version >= test_version;
}

int firstBadVersion(int n)
{
    int l = 1;
    int r = n;
    while (l < r)
    {
        const int m = (l + r) / 2;
        if (isBadVersion(m))
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int main(int argc, char **argv)
{
    test_version = 4;
    assert(firstBadVersion(5) == 4);
    test_version = 1;
    assert(firstBadVersion(1) == 1);

    return 0;
}
