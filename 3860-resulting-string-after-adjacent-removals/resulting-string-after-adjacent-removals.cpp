class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(auto &c:s){
            if(st.size()==0) st.push(c);
            else{
                char ch1=st.top(), ch2=c;
                if((ch1=='a' && ch2=='z') || (ch1=='z' && ch2=='a') || abs(ch1-ch2)==1) st.pop();
                else st.push(c);
            }
        }
        string res="";
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(begin(res),end(res));
        return res;
    }
};