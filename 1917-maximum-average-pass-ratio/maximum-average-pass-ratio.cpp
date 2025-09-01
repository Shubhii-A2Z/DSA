class Solution {
public:
    typedef pair<double,pair<int,int>> pr;

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pr> pq;

        auto delta=[&](int pass,int total)->double{
            return (double(pass+1)/(total+1))-(double(pass)/total);
        };  

        for(auto Class:classes){
            pq.push({delta(Class[0],Class[1]),{Class[0],Class[1]}});
        }

        while(extraStudents--){
            auto x=pq.top();
            pq.pop();
            pq.push({delta(x.second.first+1,x.second.second+1),{x.second.first+1,x.second.second+1}});
        }

        double ans=0;
        while(pq.size()){
            auto x=pq.top();
            pq.pop();
            ans+=(double(x.second.first)/x.second.second);
        }
        return ans/classes.size();
    }
};