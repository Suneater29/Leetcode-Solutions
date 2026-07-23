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
    void makeinorder(TreeNode* root,vector<int> &inorder){
        if(root==nullptr) return;
        makeinorder(root->left,inorder);
        inorder.push_back(root->val);
        makeinorder(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        makeinorder(root,inorder);
        return inorder;
    }
};