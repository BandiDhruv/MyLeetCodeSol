class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j1>=m || j2<0 ||j2>=m)
            return -1e9;
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        if(i==n-1)
        {
            if(j2==j1) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi=INT_MIN;
        for(int k=-1;k<=1;k++)
        {
            for(int p=-1;p<=1;p++)
            {
                if(j1==j2){
                    maxi=max(maxi,grid[i][j1]+solve(grid,i+1,j1+k,j2+p,dp));
                }else{
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(grid,i+1,j1+k,j2+p,dp));
                }
            }
        }
        return dp[i][j1][j2]=maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(grid,0,0,m-1,dp);
    }
};