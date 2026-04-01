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
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
using node = TreeNode*;
class Solution {
    int maxDiam = 0;
    int recursiveDiam(node root) {
        if(!root) return 0;
        int left = recursiveDiam(root->left);
        int right = recursiveDiam(root->right);
        maxDiam = max(maxDiam, left+right+1);
        return max(left+1, right+1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiam = 0;
        recursiveDiam(root);
        return maxDiam - 1;
    }
};
