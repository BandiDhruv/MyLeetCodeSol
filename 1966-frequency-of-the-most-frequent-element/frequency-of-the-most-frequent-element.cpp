class Solution {
public:
    vector<long > pre;
    int solve(vector<int>&nums,int k,int target_idx)
    {
        int ans=-1;
        int l=0,r=target_idx;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            long windowsize=target_idx-mid+1;
            long  currsum=pre[target_idx]-pre[mid]+nums[mid];
            long  windowsum=windowsize*nums[target_idx];
            if(windowsum-currsum<=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return target_idx-ans+1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=INT_MIN;
        pre.resize(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(solve(nums,k,i)!=-1)
            {
                res=max(res,solve(nums,k,i));
            }
        }
        return res;
    }
};