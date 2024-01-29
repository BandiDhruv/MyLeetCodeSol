class Solution {
public:
    int m=1e9+7;

    int solve(int n,int k,vector<vector<int>>&dp)
    {
        if(n==0)return 0;
        if(k==0)return 1;
        if(dp[n][k]!=-1)return dp[n][k];
        int ans=0;
        for(int i=0;i<=min(k,n-1);i++)
        {
            ans=(ans+solve(n-1,k-i,dp))%m;
        }
        return dp[n][k]=ans;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};