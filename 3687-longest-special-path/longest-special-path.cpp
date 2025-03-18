class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> graph;
    int maxLength=0, minNodes=INT_MAX;

    void dfs(int node,int par,int start,int end,int pathSum,vector<int> &nums,vector<int> &path,unordered_map<int,int> &depthMap){

        int prevDepth=depthMap.count(nums[node]) ? depthMap[nums[node]] : -1; // prev location/occurence of this node value

        while(start<=prevDepth){
            pathSum-=path[start]; // removing impact of all nodes uptil that depth, from pathSum
            start++; 
        }

        if(pathSum>maxLength){
            maxLength=pathSum;
            minNodes=end-start+1;
        }
        else if(pathSum==maxLength){
            minNodes=min(minNodes,end-start+1);
        }

        depthMap[nums[node]]=end; // mark the current location of nums[node]

        for(auto &[nbr,len]:graph[node]){
            if(nbr==par) continue;
            path.push_back(len);
            dfs(nbr,node,start,end+1,pathSum+len,nums,path,depthMap); // going on to its child node
            path.pop_back(); // backTrack
        }

        prevDepth!=-1 ? depthMap[nums[node]]=prevDepth : depthMap.erase(nums[node]); // backTrack

    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        for(auto &e:edges){
            int u=e[0], v=e[1], len=e[2];
            graph[u].push_back({v,len});
            graph[v].push_back({u,len});
        }
        unordered_map<int,int> depthMap; // marks the previous depth/lvl of node value
        vector<int> path;
        dfs(0,-1,0,0,0,nums,path,depthMap);
        return {maxLength,minNodes};
    }
};