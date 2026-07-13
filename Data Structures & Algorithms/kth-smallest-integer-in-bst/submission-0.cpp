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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        stack<TreeNode*> st;
        auto currNode = root;
        while(currNode || st.size()) {
            while(currNode) {
                st.push(currNode);
                currNode = currNode->left;
            }
            currNode = st.top(); st.pop();
            --k;
            // cout<<k<< " : "<<currNode->val<<endl;
            if(k == 0) return currNode->val;
            currNode = currNode->right;
        }
        return -3;
    }
};
