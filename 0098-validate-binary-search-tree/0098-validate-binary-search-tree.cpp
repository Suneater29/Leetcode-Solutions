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
    bool isvalid(TreeNode* root,long long minval,long long maxval){
        if(root==nullptr) return true;
        if(root->val>=maxval || root->val<=minval) return false;
        return isvalid(root->left,minval,root->val) && isvalid(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        long long minval=LLONG_MIN;
        long long maxval=LLONG_MAX;
        return isvalid(root,minval,maxval);
    }
};