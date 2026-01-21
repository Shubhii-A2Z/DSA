class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            if(!(nums[i]&1)) ans.push_back(-1);
            else{
                int val1=nums[i]^(1); // make the 0th bit 0
                int val2=1; // starting with 000...1
                bool carry=true, flag=false;
                for(int id=1;id<32;++id){
                    if(!(nums[i]&(1<<id))){
                        if(carry){ // carry is still there
                            flag=true;
                            break;
                        }
                        else carry=false; // carry is now over
                    }
                    else{ // curr bit of nums[i] is '1'
                        if(!(nums[i]&(1<<(id+1)))){ // the bit ahead is '0'
                            if(!carry){
                                val2^=(1<<id);
                            }
                            else carry=false; // carry over
                        }
                        else{
                            if(!carry) val2^=(1<<id); // no carry is there
                            else if(id!=31){
                                val2^=(1<<id);
                            }
                        }
                    }
                }
                if(flag){
                    ans.push_back(val1);
                    continue;
                }
                ans.push_back((val1<val2) ? val1 : val2);
            }
        }
        return ans;
    }
};