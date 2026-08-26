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
    void findin(TreeNode* root,vector<int> &inorder){
        if(root==nullptr) return;
        findin(root->left,inorder);
        inorder.push_back(root->val);
        findin(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        findin(root,inorder);
        int low=0;
        int high=inorder.size()-1;
        while(low<high){
            int sum=inorder[low]+inorder[high];
            if(sum>k) high--;
            else if(sum<k) low++;
            else return true;
        }
        return false;
    }
};