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
    int findleftH(TreeNode* curr){
        int ans=0;
        while(curr!=nullptr){
            ans++;
            curr=curr->left;
        }
        return ans;
    }
    int findRightH(TreeNode* curr){
        int ans=0;
        while(curr!=nullptr){
            ans++;
            curr=curr->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0; 
        int leftHeight=findleftH(root);
        int rightHeight=findRightH(root);
        if(leftHeight==rightHeight){
            return (1<<leftHeight)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};