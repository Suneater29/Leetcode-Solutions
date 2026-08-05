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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        bool flip=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            vector<int>level(qsize);
            for(int i=0;i<qsize;i++){
                TreeNode* node=q.front();
                q.pop();
                int index;
                if(flip){
                    index=i;
                }
                else{
                    index=qsize-1-i;
                }
                level[index]=node->val;
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            flip=!flip;
            ans.push_back(level);
        }
        return ans;
    }
};