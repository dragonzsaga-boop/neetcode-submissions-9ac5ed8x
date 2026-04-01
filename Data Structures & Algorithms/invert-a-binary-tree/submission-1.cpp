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
    void recursiveInvertTree(node root) {
        if(!root || (!root->left && !root->right)) return;
        swap(root->left, root->right);
        recursiveInvertTree(root->left);
        recursiveInvertTree(root->right); 
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        recursiveInvertTree(root); 
        return root;
    }
};
