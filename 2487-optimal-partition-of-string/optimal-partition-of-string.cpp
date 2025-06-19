class Solution {
public:
    int partitionString(string s) {
        int cnt=0;
        unordered_set<char> st;
        for(char ch:s){
            if(st.count(ch)){
                cnt++;
                st.clear();
            }
            st.insert(ch);
        }
        return cnt+1;
    }
};