class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ngr(t.size());
        for(int i=t.size()-1;i>=0;i--)
        {
            while(!st.empty() && t[i]>=t[st.top()])
            {
                st.pop();
            }
            if(st.empty())ngr[i]=0;
            else{
                ngr[i]=st.top()-i;
            }
            st.push(i);
        }
        return ngr;
    }
};