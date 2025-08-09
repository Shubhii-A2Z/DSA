class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<long long> q;
        q.push(0);
        int steps=0;

        unordered_set<long long> vis;

        while(q.size()){
            int sze=q.size();
            while(sze--){
                int currSum=q.front(); q.pop();
                if(currSum==amount) return steps;
                for(auto &coin:coins){
                    long long newSum=1LL*currSum+coin;
                    if(newSum>amount || vis.count(newSum)) continue;
                    q.push(newSum);
                    vis.insert(newSum);
                }
            }
            steps++;
        }

        return -1;
    }
};