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
    int level(TreeNode *root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int LST=level(root->left);
        int RST=level(root->right);
        if(abs(RST-LST)>=2) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};