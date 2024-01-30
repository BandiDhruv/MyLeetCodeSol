class Solution {
public:
    int solve(string &w1,string &w2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=w1.size() || j>=w2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j]) return 1+solve(w1,w2,i+1,j+1,dp);
        return dp[i][j]=max({solve(w1,w2,i+1,j,dp),solve(w1,w2,i,j+1,dp)});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return word1.size()+word2.size()-2*solve(word1,word2,0,0,dp);
    }
};