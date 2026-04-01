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
    bool isSameTree(node root1, node root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return (
                (root1->val == root2->val)
                && isSameTree(root1->left,root2->left) 
                && isSameTree(root1->right, root2->right)
        );
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        
        if(isSameTree(root, subRoot)) 
            return true;
        
        // if(root->left && root->right)
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
