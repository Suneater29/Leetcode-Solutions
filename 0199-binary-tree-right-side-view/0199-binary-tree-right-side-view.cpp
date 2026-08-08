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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==nullptr) return {};
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            vector<int>level;
            for(int i=0;i<qsize;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        vector<int>view;
        if(ans.size()==0) return view;
        for(auto it:ans){
            view.push_back(it.back());
        }
        return view;
    }
};