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
    bool isValidBSTRecursive(TreeNode* root, int greaterThan, int lesserThan) {
        if(!root) return true;
        if(root->val <= greaterThan || root->val >= lesserThan) return false;
        return isValidBSTRecursive(root->left, greaterThan, root->val) && 
                isValidBSTRecursive(root->right, root->val, lesserThan);
    }
public:
    bool isValidBST(TreeNode* root) {
        //return isValidBSTRecursive(root, INT_MIN, INT_MAX);
        if(!root) return true;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {INT_MIN, INT_MAX}});
        while(q.size()) {
            // int levelSize = q.size();
            // while(levelSize) {
                // --levelSize;
                auto currNode = q.front(); q.pop();
                if(currNode.first->val <= currNode.second.first ||
                    currNode.first->val >= currNode.second.second)
                    return false;
                if(currNode.first->left)
                    q.push({currNode.first->left, {currNode.second.first, currNode.first->val}});
                if(currNode.first->right)
                    q.push({currNode.first->right, {currNode.first->val, currNode.second.second}});
            // }
        }
        return true;
    }
};
