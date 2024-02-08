class Solution {
public:
    int solve(int idx,int n,vector<vector<int>> &dp)
    {
        if(n==0)return 0;
        if(n<0)return 1e9;
        if(idx*idx>n)return 1e9;
        if(dp[idx][n]!=-1)return dp[idx][n];
        int take=1+solve(idx,n-(idx*idx),dp);
        int nottake=solve(idx+1,n,dp);
        return dp[idx][n]=min(take,nottake);
    }
    int numSquares(int n) {
        vector<vector<int>> dp(sqrt(n)+1,vector<int>(n+1,-1));

        return solve(1,n,dp);
    }
};