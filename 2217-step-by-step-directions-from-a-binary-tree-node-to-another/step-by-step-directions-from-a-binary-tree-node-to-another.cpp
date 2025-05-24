class Solution {
public:
    TreeNode *lca(TreeNode *node,int s,int t){
        if(node==nullptr) return node;
        TreeNode *leftSide=lca(node->left,s,t);
        TreeNode *rightSide=lca(node->right,s,t);

        if((leftSide && rightSide) || node->val==s || node->val==t) return node;
        return leftSide==nullptr ? rightSide : leftSide;
    }

    string lcaToStart, lcaToEnd;
    void dfs(TreeNode *node,string &pathString,int s,int t){
        if(node==nullptr) return;
        if(node->val==s) lcaToStart=pathString;
        if(node->val==t) lcaToEnd=pathString;

        pathString.push_back('L');
        dfs(node->left,pathString,s,t);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(node->right,pathString,s,t);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int s, int d) {
        TreeNode *lcaNode=lca(root,s,d);

        string pathString="";
        dfs(lcaNode,pathString,s,d);

        for(auto &ch:lcaToStart) ch='U';

        return lcaToStart+lcaToEnd;
    }
};