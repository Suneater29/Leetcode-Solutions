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
    // void makeinorder(TreeNode* root,vector<int> &inorder){
    //     if(root==nullptr) return;
    //     makeinorder(root->left,inorder);
    //     inorder.push_back(root->val);
    //     makeinorder(root->right,inorder);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        // makeinorder(root,inorder);
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=nullptr && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
        // vector<int>inorder;
        // stack<TreeNode*>st;
        // TreeNode* node=root;
        // while(true){
        //     if(node!=nullptr){
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty()==true) break;
        //         node=st.top();
        //         inorder.push_back(node->val);
        //         node=node->right;
        //     }
        // }
        // return inorder;
    }
};