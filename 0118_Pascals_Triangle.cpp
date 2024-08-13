/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
*/
#include <cassert>
#include <vector>

std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> triangle(numRows);
    for (int row = 0; row < numRows; ++row)
    {
        triangle[row].resize(row + 1, 1);
        for (int col = 1; col < row; ++col)
        {
            triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }
    }
    return triangle;
}

int main(int argc, char **argv)
{
    {
        std::vector<std::vector<int>> result{{1}};
        assert(generate(1) == result);
    }
    {
        std::vector<std::vector<int>> result{{1}, {1, 1}};
        assert(generate(2) == result);
    }
    {
        std::vector<std::vector<int>> result{{1}, {1, 1}, {1, 2, 1}};
        assert(generate(3) == result);
    }
    {
        std::vector<std::vector<int>> result{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}};
        assert(generate(4) == result);
    }
    {
        std::vector<std::vector<int>> result{{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
        assert(generate(5) == result);
    }
    return 0;
}
