class Solution {
public:
    bool canPartition(int idx,int target,string &s){
        if(idx>=s.length()){
            return target==0;
        }
        int sum=0;
        for(int j=idx;j<s.length();++j){
            sum=sum*10+(s[j]-'0');
            if(sum>target) return false;
            if(canPartition(j+1,target-sum,s)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int tSum=0;
        for(int i=1;i<=n;++i){
            string s=to_string(i*i);
            tSum+=(canPartition(0,i,s) ? i*i : 0);
        }
        return tSum;
    }
};