class Solution {
public:
    int n,m;
    // int solve(string a,string b,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(i>=n || j>=m)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
        // int take=0,nottake=0;
        // if(a[i]==b[j]) take=1+solve(a,b,i+1,j+1,dp);
        // else
        //     nottake=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
    //     return dp[i][j]= max(take,nottake);
    // }
    int tab(string a,string b)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int take=0,nottake=0;
                if(a[i]==b[j]) dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size(),m=text2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return solve(text1,text2,0,0,dp);
        return tab(text1,text2);
    }
};