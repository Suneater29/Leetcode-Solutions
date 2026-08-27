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

class Nodes{
public :
    int maxSum;
    int maxNode;
    int minNode;
    Nodes(int maxSum,int maxNode,int minNode){
        this->maxSum=maxSum;
        this->maxNode=maxNode;
        this->minNode=minNode;
    }
};
class Solution {
private:
    int ans=0;
    Nodes largestSumBST(TreeNode* root){
        if(root==nullptr){
            return Nodes(0,INT_MIN,INT_MAX);
        }
        auto leftTree=largestSumBST(root->left);
        auto rightTree=largestSumBST(root->right);
        if(leftTree.maxNode < root->val && rightTree.minNode>root->val){
            int currSum=root->val+leftTree.maxSum+rightTree.maxSum;
            ans=max(ans,currSum);
            return Nodes(currSum,max(root->val,rightTree.maxNode),min(root->val,leftTree.minNode));
        }
        return Nodes(0,INT_MAX,INT_MIN);
    }
public:
    int maxSumBST(TreeNode* root) {
        largestSumBST(root);
        return ans;
    }
};