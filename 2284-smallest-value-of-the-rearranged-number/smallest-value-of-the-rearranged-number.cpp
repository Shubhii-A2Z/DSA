class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        bool isNeg=num<0;

        string st=to_string(abs(num));
        sort(begin(st),end(st),[&](auto a,auto b){
            if(isNeg) return a>b;
            return a<b;
        });

        int i=0;
        if(!isNeg) while(i<st.length() && st[i]=='0') i++;
        swap(st[i],st.front());
        
        long long val=stoll(st);
        return isNeg ? -val : val;
    }
};