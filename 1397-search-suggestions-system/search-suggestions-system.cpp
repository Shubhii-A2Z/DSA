class Solution {
public:
    
    struct TrieNode {
        TrieNode* children[26];
        set<string> s;
        bool isEnd;
        int cnt; // optional, to track number of words/prefixes passing through

        TrieNode() {
            for(int i=0;i<26;++i){
                children[i]=nullptr;
            }
            isEnd = false;
            cnt = 0;
        }
    };

    class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* node = root;
            for(auto ch:word){
                if(!node->children[ch-'a']){
                    node->children[ch-'a']=new TrieNode();
                }
                node=node->children[ch-'a'];
                node->cnt++;
                node->s.insert(word);
            }
            node->isEnd = true;
        }

        vector<vector<string>> f(string word){
            TrieNode *node=root;

            vector<vector<string>> v;
            bool flag=false;

            for(auto &ch:word){
                vector<string> temp;
                if(flag || !node->children[ch-'a']){
                    v.push_back({}); 
                    flag=true; continue;
                }
                node=node->children[ch-'a'];
                int cnt=0;
                for(auto itr=node->s.begin();itr!=node->s.end() && cnt<3;++itr){
                    temp.push_back(*itr);
                    cnt++;
                }
                v.push_back(temp);
            }

            return v;
        }

    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        Trie trie;
        for(auto &s:products){
            trie.insert(s);
        }
        
        return trie.f(searchWord);
    }
};