class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        for(auto &e:initialBoxes) q.push(e);
        int sum=0;
        vector<bool> isOpen(status.size(),0);
        while(q.size()){
            int currBox=q.front(); q.pop();
            if(status[currBox] || isOpen[currBox]){
                sum+=candies[currBox];
                auto &v1=containedBoxes[currBox];
                auto &v2=keys[currBox];
                for(auto box:v1) q.push(box);
                for(auto key:v2) isOpen[key]=true;
            }
            else{
                if(q.size()>0) q.push(currBox);
            }
        }
        return sum;
    }
};