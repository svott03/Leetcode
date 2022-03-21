/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int isBalancedH(TreeNode *root, bool &isValid);
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        bool isValid = true;
        isBalancedH(root, isValid);
        return isValid;
    }
};
int isBalancedH(TreeNode *root, bool &isValid)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int leftHeight = isBalancedH(root->left, isValid);
    int rightHeight = isBalancedH(root->right, isValid);
    int max = std::max(leftHeight, rightHeight);
    int min = std::min(leftHeight, rightHeight);
    if (max == min || max == min + 1)
    {
        return 1 + max;
    }
    else
    {
        isValid = false;
    }
    return 0;
}
// @lc code=end
