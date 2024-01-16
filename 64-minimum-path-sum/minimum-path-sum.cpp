class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>> &dp){
        if(i>=n || j>=m) return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1 && j==m-1) return grid[i][j];
        return dp[i][j]=grid[i][j]+min(solve(grid,i+1,j,dp),solve(grid,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,dp);
    }
};