class Solution {
public:
    int n,maxi;
    int findNumberOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n,1),cnt(n,1);
        maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[j]+1>dp[i])
                    {
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                        dp[i]=1+dp[j];
                        cnt[i]+=cnt[j];
                    }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)ans+=cnt[i];
        }
        return ans;
        // return solve(nums,0,);
    }
};