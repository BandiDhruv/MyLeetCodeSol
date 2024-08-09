class Solution {
public:
    int mod=1e9+7;
    long long power(long long i,long long j){
        if(j<=1)return i;
        long long ans=pow(i,j/2);
        if(j%2==0)return ((ans)%mod*(ans)%mod)%mod;
        else return ((((ans)%mod*(ans)%mod)%mod)*i)%mod;
    }
    int solve(int n,int x,int i,vector<vector<long long>> &dp){
        if(n==0)return 1;
        if(n<0 || i>n)return 0;
        if(dp[n][i]!=-1)return dp[n][i];
        long long ans=(solve(n,x,i+1,dp)%mod+solve(n-power(i,x),x,i+1,dp)%mod)%mod;
        return dp[n][i]=ans;
    }
    int numberOfWays(int n, int x){
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
        return solve(n,x,1,dp);
    }
};