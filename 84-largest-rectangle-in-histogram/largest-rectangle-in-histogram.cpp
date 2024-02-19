class Solution {
public:
    vector<int> nextSE(vector<int>&heights)
    {
        stack<int> st;
        vector<int> ans(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
      vector<int> prevSE(vector<int>&heights)
    {
        stack<int> st;
        vector<int> ans(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=nextSE(heights);
        vector<int> pse=prevSE(heights);
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int nidx=nse[i];
            int pidx=pse[i];
            if(nidx==-1)
                nidx=heights.size();
            ans=max(ans,(nidx-pidx-1)*heights[i]);
        }
        return ans;
    }
};