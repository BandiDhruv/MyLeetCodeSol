class Solution {
public:
    int n;
    vector<int> prevS(vector<int>&nums)
    {
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextS(vector<int>&nums)
    {
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextG(vector<int>&nums)
    {
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty())ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevG(vector<int>&nums)
    {
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumOfsubArrayMin(vector<int>&nums)
    {
        vector<int>nse=nextS(nums);
        vector<int>pse=prevS(nums);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+(1ll*nums[i]*1ll*(i-pse[i])*1ll*(nse[i]-i));
        }
        return ans;
    }
    long long sumOfsubArrayMax(vector<int>&nums)
    {
        vector<int>nge=nextG(nums);
        vector<int>pge=prevG(nums);
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+(1ll*nums[i]*1ll*(i-pge[i])*1ll*(nge[i]-i));
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        n=nums.size();
        long long minSum=sumOfsubArrayMin(nums);
        long long maxSum=sumOfsubArrayMax(nums);
        return maxSum-minSum;
    }
};