class Solution {
public:
    int mod=1e9+7;
    int solve(int n, int k, int target)
    {
        if(n==0 && target==0) 
        {
            return 1;
        } 
        if(n==0 || target<0) return 0;
        int take=0;
        for(int i=1;i<=k;i++)
        {
            take += solve(n-1,k,target-i);
        }
        return take;
    }
    int solvemem(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0 && target==0) 
            return 1;

        if(n==0 || target<0)
            return 0;

        if(dp[n][target]!=-1)
            return dp[n][target];

        int take=0;

        for(int i=1;i<=k;i++)
        {
            take = (take+ solvemem(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target]=take;
    }
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solvemem(n,k,target,dp);
    }
};