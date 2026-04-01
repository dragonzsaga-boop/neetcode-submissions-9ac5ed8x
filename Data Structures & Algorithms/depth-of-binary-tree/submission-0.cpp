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
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<node> q;
        int result = 0;
        q.push(root);
        q.push(nullptr);
        while(q.size()) {
            auto currNode = q.front(); q.pop();
            if(!currNode) {
                ++result;
                if(q.size()) q.push(nullptr);
                continue;
            }
            if(currNode->left)
                q.push(currNode->left);
            if(currNode->right)
                q.push(currNode->right);

        }
        return result;
    }
};
