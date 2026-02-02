class Solution {
public:
    typedef long long ll;
    multiset<ll> left,right;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll curr_min=nums[0]; //nums[0] will for sure be added in min_sum
        k--; // we already considered the first element in curr_min

        for(int i=1;i<=dist+1;++i){ //first window of size (dist+1)
            left.insert(nums[i]); //inserting all the ele in left at first
            curr_min+=(nums[i]);
        }

        while(left.size()>k){ //rebalancing the sets
            curr_min-=(*left.rbegin());
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }

        ll ans=curr_min;
        for(int i=dist+2;i<nums.size();++i){
            // Remove the element that's sliding out of the window
            if(left.find(nums[i-dist-1])!=left.end()){ //leftmost element to be removed is present in left
                curr_min-=(nums[i-dist-1]);
                left.erase(left.find(nums[i-dist-1]));
            }
            else{ //leftmost element to be removed is present in right
                right.erase(right.find(nums[i-dist-1]));
            }

            // Add the new element nums[i] to the appropriate set
            if(nums[i]<*left.rbegin()){ //rightmost element to be added is less than largest in left
                curr_min+=(nums[i]); 
                left.insert(nums[i]);
            }
            else{  //else insert in right
                right.insert(nums[i]);
            }

            while(left.size()<k){  //rebalancing the sets
                curr_min+=(*right.begin());
                left.insert(*right.begin()); //inserting the smallest ele from r to l
                right.erase(right.find(*right.begin()));
            }
            while(left.size()>k){  //rebalancing the sets
                curr_min-=(*left.rbegin());
                right.insert(*left.rbegin()); //inserting the largest ele from l to r
                left.erase(left.find(*left.rbegin()));
            }
            ans=min(ans,curr_min);
        }
        return ans;
    }
};