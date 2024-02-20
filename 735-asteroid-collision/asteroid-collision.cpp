class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<a.size();i++)
        {
            // if(!st.empty())
            // {
            //     int t=st.top();
            //     if(t>0 && a[i]>0){
            //         st.push(a[i]);
            //         continue;
            //     }
            //     if(t<0 && a[i]<0)
            //     {
            //         st.push(a[i]);
            //         continue;
            //     }
            // }
            if(a[i]>0 || st.empty() || st.top()<0)
                st.push(a[i]);
            else{
                while(!st.empty() && abs(st.top())<abs(a[i]) && st.top()>0)
                {
                    st.pop();
                }
                if(st.empty() || st.top()<0)
                    st.push(a[i]);                
                else if(st.top()==abs(a[i]))
                    st.pop();
                }
            }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};