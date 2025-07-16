class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> vis, st(begin(wordList),end(wordList));
        queue<string> q;

        q.push(beginWord);
        int steps=1;

        while(q.size()){
            int sze=q.size();
            while(sze--){
                string currWord=q.front(); q.pop();
                vis.insert(currWord);

                if(currWord==endWord) return steps; // endWord found, simply return the steps

                for(int i=0;i<currWord.length();++i){ // iterating on every character of currWord
                    int ch=currWord[i];
                    for(int j=0;j<26;++j){  // iterating on every chracter 'a'->'z' 
                        int newCh=j+'a';

                        string newWord=currWord;
                        newWord[i]=newCh;

                        if(st.count(newWord) && !vis.count(newWord)){ // we only push the new word, if it is present in the list, and also if not been previously visited
                            q.push(newWord);
                        } 
                    }
                }
            }
            steps++; // inc the steps
        }

        return 0; // endWord not possible
    }
};