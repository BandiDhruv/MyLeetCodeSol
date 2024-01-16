class Solution {
public:
    int solve(vector<vector<int>>&obstacle,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=obstacle.size() || j>=obstacle[0].size())return 0;
        if(obstacle[i][j]==1)return 0;
        if(i==obstacle.size()-1 && j==obstacle[0].size()-1 && obstacle[i][j]!=1)return 1;
          if(dp[i][j]!=-1)return dp[i][j];
        int down=0,right=0;
        if(i+1<obstacle.size() && obstacle[i+1][j]!=1)
            down=solve(obstacle,i+1,j,dp);
        if(j+1<obstacle[0].size() && obstacle[i][j+1]!=1)
            right=solve(obstacle,i,j+1,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        // if(obstacle[0][0]==1)return 0;
        vector<vector<int>> dp(obstacle.size()+1,vector<int>(obstacle[0].size()+1,-1));
        return solve(obstacle,0,0,dp);
    }
};