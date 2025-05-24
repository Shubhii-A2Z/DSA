class Solution {
public:
    typedef long long ll;
    long long sumOfLargestPrimes(string s) {

        auto check=[](string t)->bool{
            ll num=stoll(t);
            if(num==1) return false;
            for(ll i=2;i<=sqrt(num);++i){
                if(num%i==0) return false;
            }
            return true;
        };      

        unordered_map<ll,ll> mp;
        vector<ll> v;
        for(int i=0;i<s.length();++i){
            for(int j=i;j<s.length();++j){
                string temp=s.substr(i,j-i+1);
                if(check(temp)){
                    ll val=stoll(temp);
                    cout<<val<<endl;
                    mp[val]++;
                    v.push_back(val);
                }
            }
        }

        sort(begin(v),end(v));

        unordered_set<ll> vis;
        ll tSum=0, cnt=0;
        int i=v.size()-1;
        while(i>=0 && cnt<3){
            if(!vis.count(v[i])){
                tSum+=v[i];
                cnt++;
                vis.insert(v[i]);
            }
            i--;
        }
        return tSum;
    }
};