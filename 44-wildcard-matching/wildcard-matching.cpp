class Solution {
public:
    int dp[2002][2002];
    bool solve(string &s,string &p,int i,int j)
    {
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==s.size())
        {
            for(int k=p.size()-1;k>=j;k--)
                if(p[k]!='*')return false;
            return true;
        }
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]= solve(s,p,i+1,j+1);
        if(p[j]=='*')
            return dp[i][j]=solve(s,p,i+1,j) or solve(s,p,i,j+1);
        return false;
    }
    bool isMatch(string s, string p) {
        // vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0);
    }
};