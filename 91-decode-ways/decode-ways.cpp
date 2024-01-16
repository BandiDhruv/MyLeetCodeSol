class Solution {
public:

    int solve(string s,int idx,int n,vector<int>&dp)
    {
        if(idx==n)return 1;
        if(dp[idx]!=-1)return dp[idx];
        if(s[idx]=='0')return 0;
        int result=solve(s,idx+1,n,dp);
        if(idx+1<n && (s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6'))
            result+=solve(s,idx+2,n,dp);
        return dp[idx]=result;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,0,s.size(),dp);
    }
};