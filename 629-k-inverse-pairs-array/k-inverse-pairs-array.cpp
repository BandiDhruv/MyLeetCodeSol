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
    int tab(int n,int k)
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;

        // int ans=0;
        for(int i=1;i<=n;i++)
        {
            long long sum=1;
            for(int j=1;j<=k;j++)
            {
                sum+=dp[i-1][j];
                if(j>=i)sum-=dp[i-1][j-i];
                dp[i][j]=sum%m;
            }
        }
        return dp[n][k];
    }
    int kInversePairs(int n, int k) {
        // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        // return solve(n,k,dp);
        return tab(n,k);
    }
};