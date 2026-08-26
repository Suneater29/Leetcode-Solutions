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
class BSTiterator{
    stack<TreeNode*>st;
    bool reverse=true;

public:
    BSTiterator(TreeNode* root,bool isreverse){
        reverse=isreverse;
        pushin(root);
    }

    bool hasNext(){
        if(st.empty()) return false;
        return true;
    }

    int next(){
        TreeNode* topnode=st.top();
        st.pop();
        if(!reverse) pushin(topnode->right);
        else pushin(topnode->left);
        return topnode->val;
    }

private:
    void pushin(TreeNode* root){
        while(root!=nullptr){
            st.push(root);
            if(reverse==true) root=root->right;
            else root=root->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        BSTiterator left(root,false);
        BSTiterator right(root,true);
        int low=left.next();
        int high=right.next();
        while(low<high){
            if(low+high==k) return true;
            else if(low+high<k) low=left.next();
            else high=right.next();
        }
        return false;
    }
};