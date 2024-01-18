class Solution {
public:
    int M=1e9+7;
    long long solve(int m,int n,int maxi,int s,int e,vector<vector<vector<long long>>>&dp)
    {
        if(maxi<0)return 0;
        if(dp[s+2][e+2][maxi]!=-1)return dp[s+2][e+2][maxi];
        if(s>=m || s<0 || e<0 || e>=n)return 1;
        return (dp[s+2][e+2][maxi])=((solve(m,n,maxi-1,s+1,e,dp))%M+(solve(m,n,maxi-1,s-1,e,dp))%M+(solve(m,n,maxi-1,s,e+1,dp))%M+(solve(m,n,maxi-1,s,e-1,dp))%M)%M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long>>> dp(m+5,vector<vector<long long>>(n+5,vector<long long>(maxMove+5,-1)));
        return (int)solve(m,n,maxMove,startRow,startColumn,dp);
    }
};