
class Solution {
public:
    unordered_map<int,vector<int>> gr;
    vector<int> hasCoins;

    vector<vector<int>> cntCoinsSubtree; // this stores the value of array for each node's subtree
    vector<vector<int>> cntCoinsRoot; // this stores the value of array for each node when it is a root

    vector<int> minEdgesSubtree; // stores the minEdgeTraversal req for node's subtree
    vector<int> minEdgesRoot;  // stores the minEdgeTraversal req for node when it is the root

    void mergeCoins(vector<int> &par,vector<int> &child){
        par[1]+=child[0];
        par[2]+=child[1];
        par[3]+=(child[2]+child[3]);
    }

    void removeCoins(vector<int> &par,vector<int> &child){
        par[1]-=child[0];
        par[2]-=child[1];
        par[3]-=(child[2]+child[3]);
    }

    void mergeMinEdges(int &minEdges,int childVal,vector<int> &childCoins){
        if(childCoins[2]+childCoins[3]>0){
            minEdges+=(childVal+2);
        }
    }

    void removeMinEdges(int &minEdges,int childVal,vector<int> &childCoins){
        if(childCoins[2]+childCoins[3]>0){
            minEdges-=(childVal+2);
        }
    }

    void dfs_in(int node,int par){
        if(hasCoins[node]) cntCoinsSubtree[node][0]=1; // the node itself contains the coin

        for(auto &child:gr[node]){
            if(child==par) continue;
            dfs_in(child,node); // filling the details of child node

            mergeCoins(cntCoinsSubtree[node],cntCoinsSubtree[child]); // merging parent value and child value
            mergeMinEdges(minEdgesSubtree[node],minEdgesSubtree[child],cntCoinsSubtree[child]);
        }
    }

    void dfs_out(int root,int par){
        for(auto &child:gr[root]){ // making childs of root as new root of tree (re-rooting)
            if(child==par) continue;

            //Step 1: Removing the contributions of child from root
            vector<int> cntCoinsExceptChild=cntCoinsRoot[root];
            removeCoins(cntCoinsExceptChild,cntCoinsSubtree[child]); // removing cont. of child from node's details

            int minEdgesExceptChild=minEdgesRoot[root];
            removeMinEdges(minEdgesExceptChild,minEdgesSubtree[child],cntCoinsSubtree[child]); // removing cont. of child's value from node's minEdge value

            //Step 2: Adding the contribution of parent, since it is the child now
            cntCoinsRoot[child]=cntCoinsSubtree[child]; // child is the root now, hence copy the child's details in that vector
            mergeCoins(cntCoinsRoot[child],cntCoinsExceptChild); // filling details of child using parent

            minEdgesRoot[child]=minEdgesSubtree[child]; // child is the root now, hence copy the child's value in that vector
            mergeMinEdges(minEdgesRoot[child],minEdgesExceptChild,cntCoinsExceptChild); // adding the cont. of parent to child's value

            dfs_out(child,root);
        }
    }

    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int N=coins.size();

        cntCoinsSubtree=vector<vector<int>> (N,vector<int>(4,0));
        cntCoinsRoot=vector<vector<int>> (N,vector<int>(4,0));

        minEdgesSubtree=vector<int> (N,0);
        minEdgesRoot=vector<int> (N,0);

        hasCoins=coins;

        for(auto &e:edges){
            int u=e[0], v=e[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }

        dfs_in(0,-1); // dfs with 0 as initial root

        cntCoinsRoot[0]=cntCoinsSubtree[0];
        minEdgesRoot[0]=minEdgesSubtree[0];

        dfs_out(0,-1); // dfs, reversing the root and child edge one-by-one

        int mine=INT_MAX;
        for(int i=0;i<N;++i){
            mine=min(mine,minEdgesRoot[i]);
        }

        return mine;

    }
};