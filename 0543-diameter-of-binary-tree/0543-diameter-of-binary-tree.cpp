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
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftH=findHeight(root->left);
        int rightH=findHeight(root->right);
        int dia=leftH+rightH;
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);
        return max(dia,max(leftDia,rightDia));
    }
};