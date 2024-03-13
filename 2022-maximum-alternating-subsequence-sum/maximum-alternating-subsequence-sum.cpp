class Solution {
public:
    long long solve(vector<int>&nums,int f,int idx,vector<vector<long long>>&dp)
    {
        if(idx>=nums.size())return 0;
        long long take=0,nottake=0;
        if(dp[idx][f]!=-1)return dp[idx][f];
        if(f==1){
            take+=1ll*nums[idx]+solve(nums,0,idx+1,dp);
            nottake+=solve(nums,1,idx+1,dp);
        }
        else {
            take=take-1ll*nums[idx]+solve(nums,1,idx+1,dp);
            nottake+=solve(nums,0,idx+1,dp);
        }
        return dp[idx][f]=max(take,nottake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,-1));
        return max(solve(nums,0,0,dp),solve(nums,1,0,dp));
    }
};