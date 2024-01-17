class Solution {
public:
    int n;
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=n || j>=n)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1)return grid[i][j];
        int res=1e9;
        for(int idx=0;idx<n;idx++)
        {
            if(idx==j)continue;
            res=min(res,grid[i][j]+solve(grid,i+1,idx,dp));
        }
        return dp[i][j]=res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        int res=1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            res=min(res,solve(grid,0,i,dp));
        }
        return res;
    }
};