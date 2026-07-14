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
    TreeNode* root;
    int preIdx;
    TreeNode* buildTree(const vector<int>& preorder, 
                        unordered_map<int,int> &inorderHash,
                        int l, int r) {
        // if(l < 0 || r > preorder.size() || c < 0 || c >= preorder.size()) 
        if(l > r)
            return nullptr;
            // cout<<c<<" "<<endl;
        int rootVal = preorder[preIdx++];
        int splitIdx = inorderHash[rootVal];
        TreeNode* newNode = new TreeNode();
        newNode->val = rootVal;
        // cout<<"Node created : "<<newNode->val<<endl;
        if(!root) {
            root = newNode;
        }
        newNode->left = buildTree(preorder, inorderHash, l, splitIdx-1 );
        newNode->right = buildTree(preorder, inorderHash, splitIdx+1,r);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root = nullptr;
        preIdx = 0;
        unordered_map<int,int> inorderHash;
        for(int i = 0; i < inorder.size(); ++i) {
            inorderHash[inorder[i]] = i;
        }
        root = buildTree(preorder, inorderHash, 0, preorder.size()-1);
        return root;
    }
};
