class Solution {
public:
    int maxlvl(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(maxlvl(root->left),maxlvl(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left_height=maxlvl(root->left);
        int right_height=maxlvl(root->right);
        if(left_height==right_height) return root;
        else if(left_height>right_height){
            return lcaDeepestLeaves(root->left);
        }
        else{
            return lcaDeepestLeaves(root->right);
        }
    }
};