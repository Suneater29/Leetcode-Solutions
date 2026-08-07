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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            nodes[vertical][level].insert(node->val);
            if(node->left!=nullptr) q.push({node->left,{vertical-1,level+1}});
            if(node->right!=nullptr) q.push({node->right,{vertical+1,level+1}});
        }
        vector<vector<int>>traversal;
        for(auto i:nodes){
            vector<int>col;
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            traversal.push_back(col);
        }
        return traversal;
    }
};