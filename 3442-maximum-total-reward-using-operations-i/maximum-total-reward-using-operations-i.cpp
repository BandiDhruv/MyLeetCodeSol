class Solution {
public:

    int solve(int i,int tot,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size())return 0;
        if(dp[tot]!=-1)return dp[tot];
        int nottake=solve(i+1,tot,nums,dp);
        int idx=upper_bound(nums.begin(),nums.end(),tot+nums[i])-nums.begin();
        int take=nums[i]+solve(idx,tot+nums[i],nums,dp);
        return dp[tot]=max(take,nottake);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        vector<int> dp(2e3,-1);
        return solve(0,0,rewardValues,dp);
    }
};