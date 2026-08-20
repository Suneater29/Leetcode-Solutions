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
    TreeNode* binaryTree(vector<int> &preorder,vector<int> &inorder,int prestart,int instart,int preend,int inend,map<int,int> &mpp){
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int rootind=mpp[root->val];
        int remaining=rootind-instart;
        root->left=binaryTree(preorder,inorder,prestart+1,instart,prestart+remaining,rootind-1,mpp);
        root->right=binaryTree(preorder,inorder,prestart+remaining+1,rootind+1,preend,inend,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int m=inorder.size();
        map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return binaryTree(preorder,inorder,0,0,n-1,m-1,mpp);
    }
};