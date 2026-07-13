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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> partRes;

        if(!root) return (res);
        q.push(root);
        while(q.size()) {
            int levelSize = q.size();
            while(levelSize) {
                --levelSize;
                auto currNode = q.front(); q.pop();
                partRes.push_back(currNode->val);

                if(currNode->left) 
                    q.push(currNode->left);
                if(currNode->right) 
                    q.push(currNode->right);
            }
                // if(levelSize == 0) {
                    res.emplace_back(move(partRes));
                // }
        }
        return res;
    }
};
