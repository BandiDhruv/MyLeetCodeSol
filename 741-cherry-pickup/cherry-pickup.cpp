class Solution {
public:
    int n;
    long long solve(vector<vector<int>>&grid,int i,int j,int i1,int j1,vector<vector<vector<vector<int>>>>&dp)
    {
        if(i>=n || j>=n || j1>=n || i1>=n || grid[i][j]==-1 || grid[i1][j1]==-1)return -1e5;
         if(i==n-1 && j==n-1) return grid[i][j];
        if(i1==n-1 && j1==n-1) return grid[i1][j1];
        if(dp[i][j][i1][j1]!=-1)return dp[i][j][i1][j1];
        long long ans=0;
        if(i==i1 && j==j1)ans+= grid[i][j];
        else ans+=grid[i][j]+grid[i1][j1];
        ans+=max({solve(grid,i+1,j,i1+1,j1,dp),solve(grid,i+1,j,i1,j1+1,dp),solve(grid,i,j+1,i1+1,j1,dp),solve(grid,i,j+1,i1,j1+1,dp)});
        return dp[i][j][i1][j1]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        // bool f=false;
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1))));
        return max(1ll*0,solve(grid,0,0,0,0,dp));
    } 
};