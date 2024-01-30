class Solution {
public:
    int solve(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if(i==s.size() && j==t.size()) return 1;
        if(i>s.size() || j>s.size()) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=solve(s,t,i+1,j+1,dp)+solve(s,t,i+1,j,dp);
        return dp[i][j]=solve(s,t,i+1,j,dp);
    }

    // int tab(string &s, string &t) {
    //     vector<vector<double>> dp(s.size() + 1, vector<double>(t.size() + 1, 0));
    //     dp[s.size()][t.size()] = 1;

    //     for (int i = s.size() - 1; i >= 0; i--) {
    //         for (int j = t.size() - 1; j >= 0; j--) {
    //             if (s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
    //             else dp[i][j] = dp[i + 1][j];
    //         }
    //     }

    //     return dp[0][0];
    // }


    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s,t,0,0,dp);
        // return tab(s,t);
    }
};