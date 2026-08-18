/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentPointer){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currnode=q.front();
            q.pop();
            if(currnode->left!=nullptr){
                parentPointer[currnode->left]=currnode;
                q.push(currnode->left);
            }
            if(currnode->right!=nullptr){
                parentPointer[currnode->right]=currnode;
                q.push(currnode->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentPointer;
        parents(root,parentPointer);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int dist=0;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            dist++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right!=nullptr && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentPointer[node] && !visited[parentPointer[node]]){
                    q.push(parentPointer[node]);
                    visited[parentPointer[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};