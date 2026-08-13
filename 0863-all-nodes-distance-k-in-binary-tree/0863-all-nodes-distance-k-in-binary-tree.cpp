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
    void parentmap(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=nullptr){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right!=nullptr){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> bfs(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int currentLevel = 0;
        while (!q.empty()) {
            int size = q.size();
            if (currentLevel++ == k) break;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && visited.find(parent[node]) == visited.end()) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr) return {};
        unordered_map<TreeNode*,TreeNode*>parent;
        parentmap(root,parent);
        return bfs(target,parent,k);
    }
};