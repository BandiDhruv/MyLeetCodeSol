class Solution {
public:
    int solve(vector<int>&nums,int i,int sum,vector<vector<int>>&dp){
        if(i==nums.size())
        {   
            if(sum==0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take=nums[i]+solve(nums,i+1,(sum+nums[i])%3,dp);
        int nottake=solve(nums,i+1,sum,dp);
        return dp[i][sum]=max(take,nottake);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(1+nums.size(),vector<int>(3+1,-1));
        return solve(nums,0,0,dp);
    }
};