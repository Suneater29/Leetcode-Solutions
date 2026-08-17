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
    TreeNode* makeTree(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend,map<int,int> &mpp){
        if(prestart>preend || instart>inend) return nullptr;
        TreeNode* node=new TreeNode(preorder[prestart]);
        int innode=mpp[node->val];
        int rem=innode-instart;
        node->left=makeTree(preorder,prestart+1,prestart+rem,inorder,instart,innode-1,mpp);
        node->right=makeTree(preorder,prestart+rem+1,preend,inorder,innode+1,inend,mpp);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        int n=preorder.size();
        int m=inorder.size();
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return makeTree(preorder,0,n-1,inorder,0,m-1,mpp);
    }
};