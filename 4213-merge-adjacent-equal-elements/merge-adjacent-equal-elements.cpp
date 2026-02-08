class Solution {
public:
    typedef long long ll;
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<ll> s;

        for(int e:nums){
            if(!s.size()) s.push(e);
            else{
                if(s.top()==e){
                    s.pop();
                    ll newE=2*e;
                    while(s.size()){
                        if(s.top()==newE){
                            newE*=2;
                            s.pop();
                        }
                        else break;
                    }
                    s.push(newE);
                }
                else s.push(e);
            }
        }

        vector<ll> v;
        while(s.size()){
            v.push_back(s.top());
            s.pop();
        }

        reverse(begin(v),end(v));
        return v;
    }
};