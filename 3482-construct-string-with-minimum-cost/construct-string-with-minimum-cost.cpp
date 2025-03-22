class Solution {
public:
    typedef long long ll;
    #define M 1000000007
    int P=31, N=5e4+10;
    ll dp[50001];

    vector<ll> p_pow, inv_p_pow;

    string s;
    vector<ll> s_hash;

    vector<int> uniq_word_lengths;
    unordered_map<int, int> cost_per_str; 

    // a^b % M
    ll FastPower (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % M;
            a = (a*a) % M;
            b /= 2;
        }
        return ans;
    }
    
    void ComputePower() {
        if (!p_pow.empty()) return;
        
        p_pow.resize(N, 1);
        for (int i = 1; i < N; i ++)
            p_pow[i] = (p_pow[i-1] * P) % M;
        
        inv_p_pow.resize(N, 1);
        
        inv_p_pow[N-1] = FastPower (p_pow[N-1], M-2);
        for (int i = N-2; i > 0; i --)
            inv_p_pow[i] = (inv_p_pow[i+1] * P) % M;
    }
    
    vector<ll> HashIt (const string& s) {
        int S = s.size();
        vector<ll> prefix_hash(S+1, 0);

        for (int i = 1; i <= S; i++) {
            ll cur = (p_pow[i] * (s[i-1]-'a'+1)) % M;
            prefix_hash[i] = (prefix_hash[i-1] + cur) % M;
        }
        return prefix_hash;
    }
    
    inline ll HashOfRange (int l, int r) {
        if (r > s.length()) return -1;
        
        ll hash = (s_hash[r] - s_hash[l-1] + M) % M;
        return (hash * inv_p_pow[l-1]) % M;
    }
    
    int MinCost (int ind) {
        if (ind >= s.length()) return 0;
        
        ll &ans = dp[ind];
        if (ans != -1) return ans;
        ll res = INT_MAX;
        
        for (int& len : uniq_word_lengths) {            
            int hash = HashOfRange(ind+1, ind+len);
            
            auto it = cost_per_str.find(hash);
            if (it == cost_per_str.end()) continue;
            
            res = min (res, ll(it->second) + ll(MinCost(ind+len)));
        }
        return ans=res;
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        ComputePower();
        s=target;
        s_hash=HashIt(target);

        set<int> wordLen;
        for(auto &w:words) wordLen.insert(w.length());
        uniq_word_lengths=vector<int> (begin(wordLen),end(wordLen));

        for(int i=0;i<words.size();++i){
            int len=words[i].length();
            ll hash=HashIt(words[i]).back();

            auto it=cost_per_str.find(hash);
            if(it==cost_per_str.end()) cost_per_str.insert({hash,costs[i]});
            else it->second=min(it->second,costs[i]);
        }

        memset(dp,-1,sizeof(dp));
        int ans=MinCost(0);
        return ans==INT_MAX ? -1 : ans;
    }
};