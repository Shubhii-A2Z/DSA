class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]<9){
            digits[n-1]++;
            return digits;
        }
        vector<int> ans;
        ans.push_back(0);
        int carry=1;
        for(int i=n-2;i>=0;i--){
            int ele=digits[i]+carry;
            carry=0;
            if(ele==10){
                carry=1;
                ele=0;
            }
            ans.push_back(ele);
        }
        if(carry==1) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};