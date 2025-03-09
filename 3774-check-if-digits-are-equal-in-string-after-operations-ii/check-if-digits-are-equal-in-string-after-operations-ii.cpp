class Solution {
public:
    typedef long long ll;

    ll nCkMod5(ll n,ll k){ // n and k are both less than 5
        if(k>n) return 0;
        int factorialMod5[]={1,1,2,1,4}; // factorial values for 0-4 (mod 5)
        int numerator=factorialMod5[n];
        int denominator=(factorialMod5[k]*factorialMod5[n-k])%5;
        for(int cand=0;cand<=4;++cand){
            if((denominator*cand)%5==1){
                return (numerator*cand)%5;
            }
        }
        return 0;
    }

    ll nCkMod2(ll n,ll k){ // here n and k will be less than 2
        return (k>n) ? 0 : 1;
    }

    int nCkLucaModP(int n,int k,int p){
        ll res=1;
        while(n>0 || k>0){
            int nDigit=n%p, kDigit=k%p;
            if(kDigit>nDigit) return 0;
            if(p==2) res=(res*nCkMod2(nDigit,kDigit))%p; // using luca theorem
            else res=(res*nCkMod5(nDigit,kDigit))%p; // using luca theorem
            n/=p;
            k/=p;
        }
        return res;
    }

    int nCkMod10(int n,int k){ // (nCk-mod10) can be found out by finding (nCk-mod2) and (nCk-mod5) -> Chinese Remainder Theorem
        int mod2Val=nCkLucaModP(n,k,2); // lucas method
        int mod5Val=nCkLucaModP(n,k,5); // lucas method
        for(int cand=0;cand<=9;++cand){
            if(cand%2==mod2Val && cand%5==mod5Val){
                return cand;
            }
        }
        return 0;
    }

    bool hasSameDigits(string s) {
        int n=s.length();
        ll sum1=0, sum2=0;
        for(int i=0;i<n-1;++i){
            int coeff=nCkMod10(n-2,i);
            int val1=s[i]-'0';
            int val2=s[i+1]-'0';
            sum1=(sum1+(coeff*val1))%10; sum2=(sum2+(coeff*val2))%10;
        }
        return sum1==sum2;
    }
};