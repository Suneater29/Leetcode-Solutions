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
    TreeNode* findlastright(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        return findlastright(root->right);
    }
    TreeNode* connect(TreeNode* root){
        if(root->left==nullptr) return root->right;
        else if(root->right==nullptr) return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* lastright=findlastright(root->left);
        lastright->right=rightchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return connect(root);
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->val>key){
                if(curr->left!=nullptr && curr->left->val==key){
                    curr->left=connect(curr->left);
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->right!=nullptr && curr->right->val==key){
                    curr->right=connect(curr->right);
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};