class Solution {
public:
    int solve(int n,int idx,vector<int>&dp)
    {
        if(idx>n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        if(idx==n)return 1;
        return dp[idx]=solve(n,idx+1,dp)+solve(n,idx+2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,0,dp);
    }
};