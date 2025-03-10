class Solution {
public:
    long long countAtleastK(string &word,int k){
        auto isVowel=[](char ch)->bool{
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        };

        unordered_map<char,int> mp; //{vowel,count}
        int cnt=0; // consonant count
        long long res=0;

        int i=0,j=0;
        while(j<word.size()){
            char ch=word[j];
            if(!isVowel(ch)) cnt++;
            else mp[word[j]]++;
            while(mp.size()==5 && cnt>=k){
                res+=(word.length()-j);
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(!mp[word[i]]) mp.erase(word[i]);
                }
                else cnt--;
                i++;
            }
            j++;
        }

        return res;
    }

    long long countOfSubstrings(string word, int k) {
        return countAtleastK(word,k)-countAtleastK(word,k+1);
    }
};