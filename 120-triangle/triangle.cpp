class Solution {
public:
    int solve(vector<vector<int>>& triangle,int idx,int j,vector<vector<int>>&dp)
    {
        if(j>=triangle.size() || idx>=triangle[j].size() )return 0;
        if(dp[j][idx]!=-1)return dp[j][idx];
        return dp[j][idx]=triangle[j][idx]+min(solve(triangle,idx,j+1,dp),solve(triangle,idx+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(200+1,vector<int>(201,-1));
        int ans=solve(triangle,0,0,dp);
        return ans;
    }
};