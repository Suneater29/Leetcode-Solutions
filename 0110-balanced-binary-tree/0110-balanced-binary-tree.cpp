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
    int findHeight(TreeNode* root){
        if(root==nullptr) return 0;
        int leftHeight=findHeight(root->left);
        int rightHeight=findHeight(root->right);
        if(leftHeight==-1 || rightHeight==-1) return -1;
        if(abs(leftHeight-rightHeight)>1) return -1;
        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        int height=findHeight(root);
        if(height<0) return false;
        else return true;
    }
};