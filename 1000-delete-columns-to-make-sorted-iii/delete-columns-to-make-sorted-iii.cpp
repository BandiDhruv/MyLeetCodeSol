class Solution {
public:
    int solve(vector<string>&s,int i,int prev,int n,int m,vector<vector<int>>&dp){
        if(i>=m)
            return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int notdelete,delet=1+solve(s,i+1,prev,n,m,dp),f=0;
        for(int j=0;j<n;j++){
            if(prev!=-1 && s[j][prev]>s[j][i])
            {
                f=1;
            }
        }
        if(f==0)
            notdelete=solve(s,i+1,i,n,m,dp);
        return dp[i][prev+1]=min(delet,notdelete);
    }
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(strs,0,-1,n,m,dp);
    }
};