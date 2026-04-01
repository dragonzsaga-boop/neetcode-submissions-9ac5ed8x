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
    int isRecursiveBalanced(node root, bool &isBalanced) {
        if(!isBalanced) return 0;
        if(!root) return 0;
        int left = isRecursiveBalanced(root->left, isBalanced);
        int right = isRecursiveBalanced(root->right, isBalanced);
        // cout<<root->val<<" : \tL = "<<left<<"\tR = "<<right<<endl;
        if(abs(left-right) > 1) {
            isBalanced = false; 
            return 0;
        }
        return max(left, right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        isRecursiveBalanced(root, isBalanced);
        return isBalanced;
    }
};
