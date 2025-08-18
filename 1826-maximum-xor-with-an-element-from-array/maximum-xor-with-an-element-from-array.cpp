class Solution {
public:
    
    class TrieNode{
    public:
        int count;
        map<int,TrieNode*> children;
        TrieNode(){
            count=0;
        }
    };

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
                    ans+=(1<<i); // add the contribution of ith bit in XOR value
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

    struct state{
        int a,b,c;
    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode *root=new TrieNode();
        sort(begin(nums),end(nums));

        vector<state> query; // implementing offline queries with sorting

        for(int i=0;i<queries.size();++i){
            int x=queries[i][0], m=queries[i][1];
            query.push_back({i,x,m});
        }

        sort(begin(query),end(query),[&](state &s1,state &s2){
            return s1.c<s2.c;
        });

        vector<int> v(queries.size());

        int i=0;
        for(auto &q:query){
            int idx=q.a, x=q.b, m=q.c;

            while(i<nums.size() && nums[i]<=m){ // Insert nums into the trie only up to the current m
                insert(root,nums[i]);
                i++;
            }

            if(i==0) v[idx]=-1; // all elements r smaller than m
            else v[idx]=maxXor(root,x); // For each query, computing max XOR with available nums <= m
        }

        return v;
    }
};