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

class Solution {
    bool isValidBST(TreeNode* root, int greaterThan, int lesserThan) {
        if(!root) return true;
        if(root->val <= greaterThan || root->val >= lesserThan) return false;
        return isValidBST(root->left, greaterThan, root->val) && 
                isValidBST(root->right, root->val, lesserThan);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
