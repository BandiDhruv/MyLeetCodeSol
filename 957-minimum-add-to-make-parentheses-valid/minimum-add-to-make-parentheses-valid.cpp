class Solution {
public:
    int minAddToMakeValid(string s) {
    //    int open=0,close=0;
    //    for(int i=0;i<s.size();i++)
    //    {
    //         if(s[i]=='(')
    //             open++;
    //         if(s[i]==')')
    //             close++;
    //    }
       
    //    int ans=0;
    //    if(close>open)
    //         ans+=close-open;
    //     else
    //         ans+=open-close;
    //     return ans;
        stack<char> st;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(!st.empty())
                st.pop();
            else
                count+=1;
        }
        return count+st.size();
    }
};