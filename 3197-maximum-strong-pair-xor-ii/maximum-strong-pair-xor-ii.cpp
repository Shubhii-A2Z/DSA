
typedef long long ll;

class TrieNode{
public:
    int count;
    unordered_map<int,TrieNode*> children;
    TrieNode(){
        count=0;
    }
};

class Solution {
public:

    void insert(TrieNode *root,int num){
        TrieNode *curr=root;
        curr->count++;
        for(int i=31;i>=0;--i){ // starting from MSB to LSB
            if(num&(1<<i)){ // ith bit is set
                if(!curr->children.count(1)){ // node is not present, we need to create one
                    TrieNode *child=new TrieNode();
                    curr->children[1]=(child);
                }
                curr=curr->children[1]; //move to child
            }
            else{ // ith bit not set
                if(!curr->children.count(0)){ // node is not present, we need to create one
                    TrieNode *child=new TrieNode();
                    curr->children[0]=(child);
                }
                curr=curr->children[0]; //move to child
            }
            curr->count++; // increase count inside child by 1
        }
    }

    void remove(TrieNode *root,int num){
        TrieNode *curr=root;
        curr->count--; // decrease count inside root by 1
        for(int i=31;i>=0;--i){ // starting from MSB to LSB
            if(num&(1<<i)) curr=curr->children[1]; //move to child
            else curr=curr->children[0]; //move to child
            curr->count--; // decrease count inside child by 1
        }
    }

    int maxXor(TrieNode *root,int currVal){ // finds the max XOR value out of all possible pairs 
        TrieNode *curr=root;
        int ans=0;
        for(int i=31;i>=0;--i){
            if(currVal&(1<<i)){ // ith bit in val is set, hence we need 0 to maximise XOR
                if(curr->children.count(0) && curr->children[0]->count>0){ // valid 0 found, hurray!!
                    ans+=(1<<i); // 
                    curr=curr->children[0];
                }
                else curr=curr->children[1]; // 0 not found, move to 1
            }
            else{ // ith bit in val is not set, hence we need 1 to maximise XOR
                if(curr->children.count(1) && curr->children[1]->count>0){ // valid 1 found, hurray!!
                    ans+=(1<<i); // add the contribution of ith bit in XOR value
                    curr=curr->children[1];
                }
                else curr=curr->children[0]; // 1 not found, move to 0
            }
        }
        return ans;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        sort(begin(nums),end(nums));
        TrieNode *root=new TrieNode();

        int ans=0;
        int l=0,r=0;
        while(l<nums.size()){
            //current element to be considered is nums[l]
            while(r<nums.size() && nums[r]<=2*nums[l]){ // finding all the numbers which can form pair with curr element
                insert(root,nums[r]);
                r++;
            }
            ans=max(ans,maxXor(root,nums[l]));
            remove(root,nums[l]); // as l is moved right, hence nums[l] is to be removed from XOR_Trie
            l++;
        }

        return ans;
    }

};