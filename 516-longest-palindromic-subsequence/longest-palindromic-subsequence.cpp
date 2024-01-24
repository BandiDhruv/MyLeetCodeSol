class Solution {
public:
    int solve(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==j)
            return 1;
        if(s[i]==s[j]) return 2+solve(s,i+1,j-1,dp);
        return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        if(s.size()==1)return 1;
        vector<vector<int>> dp((s.size()+1),vector<int>((s.size()+1),-1));
        return solve(s,0,s.size()-1,dp);
    }
};