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
    TreeNode* makeBST(vector<int> &preorder,int &root,int boundary){
        if(root==preorder.size() || preorder[root]>boundary) return nullptr;
        TreeNode* node=new TreeNode(preorder[root++]);
        node->left=makeBST(preorder,root,node->val);
        node->right=makeBST(preorder,root,boundary);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int root=0;
        return makeBST(preorder,root,INT_MAX);
    }
};