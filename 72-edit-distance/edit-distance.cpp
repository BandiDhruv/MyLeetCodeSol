class Solution {
public:
    int n,m,dp[502][502];
    int solve(string &s1,string &s2,int i,int j)
    {
        if(j==m)
            return n-i;
        if(i==n)
            return m-j;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j]) return solve(s1,s2,i+1,j+1);
        return dp[i][j]=min({1+solve(s1,s2,i,j+1),1+solve(s1,s2,i+1,j),1+solve(s1,s2,i+1,j+1)});
    }
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};