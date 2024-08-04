class Solution {
public:
    long long mod=(int)1e9+7;
vector<long long> pse(vector<int>&nums){
        stack<long long> st;
        vector<long long> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())
                ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<long long> nse(vector<int>&nums){
        stack<long long> st;
        vector<long long> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            if(st.empty())
                ans[i]=nums.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<long long> t1=nse(arr);
        vector<long long>t2=pse(arr);
        long long ans=0;
        for(auto it:t1)cout<<it<<" ";
        cout<<endl;
        for(auto it:t2)cout<<it<<" ";
        cout<<endl;
        for(int i=0;i<arr.size();i++){
            ans=ans+1ll*arr[i]*((t1[i]-i)*(i-t2[i]));
            ans%=mod;
        }
        return ans;
    }
};