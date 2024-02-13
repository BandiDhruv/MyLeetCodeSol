class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        vector<int> nextG(n2.size());
        stack<int> st;
        for(int i=n2.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(n2[i]);
                nextG[i]=-1;
            }
            else{
                if(n2[i]<st.top())
                {
                    nextG[i]=st.top();
                }
                else{
                    while(!st.empty() && n2[i]>st.top())
                    {
                        st.pop();
                    }
                    if(st.empty())
                        nextG[i]=-1;
                    else
                        nextG[i]=st.top();
                }
            }
            st.push(n2[i]);
        }
        vector<int> ans(n1.size());
        unordered_map<int,int> mp;
        for(int i=0;i<n2.size();i++){
            mp[n2[i]]=i;
        }
        for(int i=0;i<n1.size();i++)
        {
            ans[i]=nextG[mp[n1[i]]];   
        }
        return ans;
    }
};