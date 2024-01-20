class Solution {
public:
    bool solve(vector<int>&nums,int sum,int idx,vector<vector<int>> &dp)
    {
        if(idx>=nums.size())return false;
        if(sum<0)return false;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        if(sum==0)return true;
        bool take=solve(nums,sum-nums[idx],idx+1,dp);
        bool nottake=solve(nums,sum,idx+1,dp);
        return dp[idx][sum]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)return false;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,sum/2,0,dp);
    }
};