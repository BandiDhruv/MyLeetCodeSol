class Solution {
public:
    int solve(vector<vector<int>>&triangle,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=triangle.size() || j>=triangle[i].size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=triangle[i][j] +min(solve(triangle,i+1,j,dp),solve(triangle,i+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(202,vector<int>(202,-1));
        return solve(triangle,0,0,dp);
    }
};