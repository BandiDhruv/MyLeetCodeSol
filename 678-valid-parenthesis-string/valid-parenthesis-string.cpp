class Solution {
public:
    bool checkValidString(string s) {
        int stcount=0;
        stack<char>st,star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(!st.empty())
                    st.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
            else star.push(i);
            // cout<<st.size()<<"  "<<stcount<<endl;
        }
        while(!st.empty() && !star.empty() && st.top()<star.top())
        {
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};