class Solution {
public:
    vector<int> solve(vector<int> &nums2){
        stack<int> st;
        int n=nums2.size();
        vector<int> ans(n);
        ans[n-1]=-1;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
                ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums2[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]]=i;
        vector<int> nge=solve(nums2);
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=nge[mp[nums1[i]]];
        }
        return ans;
    }
};