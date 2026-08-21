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
    void makelist(TreeNode* root,TreeNode* &prev){
        if(root==nullptr) return;
        makelist(root->right,prev);
        makelist(root->left,prev); 
        root->right=prev;
        root->left=nullptr;
        prev=root;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=nullptr;
        makelist(root,prev);
    }
};