class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=INT_MIN;
        for(auto it:s)
        {
            if(it=='(')st.push(it);
            else if(it==')')st.pop();
            ans=max(ans,(int)st.size());
        }
        return ans;
    }
};