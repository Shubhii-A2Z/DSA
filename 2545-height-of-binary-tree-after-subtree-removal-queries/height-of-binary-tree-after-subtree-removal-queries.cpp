class Solution {
public:
    vector<int> stIdx,edIdx,depth;
    int countNodes(TreeNode *root){
        if(!root) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    void EulerTour(TreeNode *root,int &idx){
        stIdx[root->val]=idx;
        if(root->left){
            idx++;
            EulerTour(root->left,idx);
        }
        if(root->right){
            idx++;
            EulerTour(root->right,idx);
        }
        edIdx[root->val]=idx;
    }

    void calculateDepth(TreeNode *root,int ht){
        depth[stIdx[root->val]]=ht;
        if(root->left) calculateDepth(root->left,ht+1);
        if(root->right) calculateDepth(root->right,ht+1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n=countNodes(root);
        stIdx.resize(n+1), edIdx.resize(n+1), depth.resize(n+1);

        int idx=0;
        EulerTour(root,idx);
        calculateDepth(root,0);

        vector<int> prefMax(n+2,0), suffMax(n+2,0);
        for(int i=1;i<=n;++i){
            prefMax[i]=max(depth[i],prefMax[i-1]);
        }
        for(int i=n;i>=1;--i){
            suffMax[i]=max(depth[i],suffMax[i+1]);
        }

        vector<int> ans;
        for(auto &q:queries){
            int l=stIdx[q], r=edIdx[q];
            ans.push_back(max(prefMax[l-1],suffMax[r+1]));
        }

        return ans;
    }
};