class Solution {
public:
    vector<int> pse(vector<int>&h){
        stack<int> st;
        vector<int> ans(h.size());
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>&h){
        stack<int> st;
        vector<int> ans(h.size());
        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            if(st.empty())ans[i]=h.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) {
        int l=0,r=h.size()-1;
        vector<int> p=pse(h);
        vector<int> n=nse(h);
        int ans=INT_MIN;
        for(int i=0;i<h.size();i++){
            // cout<<h[i]<<" "<<n[i]<<" "<<p[i]<<endl;
            ans=max(ans,h[i]*(n[i]-p[i]-1));
        }
        return ans;
    }
};