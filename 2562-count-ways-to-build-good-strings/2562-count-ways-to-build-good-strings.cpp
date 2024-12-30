class Solution {
public:
    int mod=1e9+7;
    int dp[1000001];
    int solve(int low, int high, int zero, int one,int cnt){
        if(cnt>high)return 0;
        if(dp[cnt]!=-1)
            return dp[cnt];
        dp[cnt]=(cnt>=low)?1:0;
        dp[cnt]+=solve(low,high,zero,one,cnt+zero);
        dp[cnt]%=mod;
        dp[cnt]+=solve(low,high,zero,one,cnt+one);
        dp[cnt]%=mod;
        return dp[cnt];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int cnt=0;
        memset(dp,-1,sizeof(dp));
        return solve(low,high,zero,one,cnt);
    }
};