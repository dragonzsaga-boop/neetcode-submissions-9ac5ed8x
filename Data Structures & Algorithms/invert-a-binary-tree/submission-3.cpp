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
        if(!root) return;
        swap(root->left, root->right);
        recursiveInvertTree(root->left);
        recursiveInvertTree(root->right); 
    }
    node iterativeInvertTree(node root) {
        stack<node> st;
        st.push(root);
        while(st.size()) {
            auto currNode = st.top(); st.pop();
            if(!currNode) continue;
            
            swap(currNode->left, currNode->right);
            
            st.push(currNode->left);
            st.push(currNode->right);
        }
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        // recursiveInvertTree(root); return root;
        return iterativeInvertTree(root);
    }
};
