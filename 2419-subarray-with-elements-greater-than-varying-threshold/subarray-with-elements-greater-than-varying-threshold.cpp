class Solution {
public:
    vector<int> s1(vector<int>&nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> s2(vector<int>&nums){
        int n=nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
       vector<int>nse=s1(nums),pse=s2(nums); 
       for(auto it:nse)cout<<it<<" ";
       cout<<endl;
       for(auto it:pse)cout<<it<<" ";
       cout<<endl;
       for(int i=0;i<nums.size();i++){
        int ele=nums[i];
        int nidx=nse[i];
        int pidx=pse[i];
        int len=nidx-pidx-1;
        int k=threshold/len;
        if(ele>k){cout<<i<<endl;return len;}
       }
       return -1;
    }
};