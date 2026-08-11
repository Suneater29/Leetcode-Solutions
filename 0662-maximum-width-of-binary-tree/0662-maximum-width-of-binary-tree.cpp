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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxwidth=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int mini=q.front().second;
            int n=q.size();
            int first;
            int last;
            for(int i=0;i<n;i++){
                long long curri=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curri;
                if(i==n-1) last=curri;
                if(node->left!=nullptr) q.push({node->left,curri*2+1});
                if(node->right!=nullptr) q.push({node->right,curri*2+2});
            }
            maxwidth=max(maxwidth,last-first+1);
        }
        return maxwidth;
        // if(root==nullptr) return 0;
        // int width=0;
        // queue<pair<TreeNode*,int>>q;
        // q.push({root,0});
        // while(!q.empty()){
        //     int mini=q.front().second;
        //     int qsize=q.size();
        //     int first;
        //     int last;
        //     for(int i=0;i<qsize;i++){
        //         long long currind=q.front().second-mini;
        //         TreeNode* node=q.front().first;
        //         q.pop();
        //         if(i==0) first=currind;
        //         if(i==qsize-1) last=currind;
        //         if(node->left!=nullptr){
        //             q.push({node->left,currind*2+1});
        //         }
        //         if(node->right!=nullptr){
        //             q.push({node->right,currind*2+2});
        //         }
        //     }
        //     width=max(width,last-first+1);
        // }
        // return width;
    }
};