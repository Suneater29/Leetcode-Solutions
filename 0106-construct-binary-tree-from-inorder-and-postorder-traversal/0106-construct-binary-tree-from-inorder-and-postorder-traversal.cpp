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
    TreeNode* tree(vector<int> &postorder,vector<int> &inorder,int poststart,int postend,int instart,int inend,map<int,int> &mpp){
        if(poststart>postend || instart>inend) return nullptr;
        TreeNode* root=new TreeNode(postorder[postend]);
        int rootind=mpp[root->val];
        int remaining=rootind-instart;
        root->left=tree(postorder,inorder,poststart,poststart+remaining-1,instart,rootind-1,mpp);
        root->right=tree(postorder,inorder,poststart+remaining,postend-1,rootind+1,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int m=inorder.size();
        map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return tree(postorder,inorder,0,n-1,0,m-1,mpp);
    }
};