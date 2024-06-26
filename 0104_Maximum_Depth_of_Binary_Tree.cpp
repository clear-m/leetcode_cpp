#include <algorithm>
#include <cassert>

/*
Time: 𝑂(𝑛)
Space: 𝑂(1)
*/

// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:
// Input: root = [1,null,2]
// Output: 2
// Constraints:
// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main(int argc, char **argv)
{
    // [3,9,20,null,null,15,7]
    TreeNode fifteen(15);
    TreeNode seven(7);
    TreeNode twenty(20, &fifteen, &seven);
    TreeNode nine(9);
    TreeNode third(3, &nine, &twenty);
    TreeNode* root = &third;

    assert(maxDepth(root) == 3);

    return 0;
}
