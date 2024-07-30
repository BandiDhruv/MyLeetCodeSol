class Solution {
public:
    int dp[1001][1002][4];
    int solve(vector<int>&rating,int idx,int k,int prev){
        if(k==0)return 1;
        if(idx>=rating.size())return 0;
        if(dp[idx][prev+1][k]!=-1)return dp[idx][prev+1][k];
        int take=0,nottake=0;
        if(prev==-1 || rating[idx]>rating[prev]){
            take+=solve(rating,idx+1,k-1,idx);
        }
        nottake=solve(rating,idx+1,k,prev);
        return dp[idx][prev+1][k]=take+nottake;
    }
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(rating,0,3,-1);
        memset(dp,-1,sizeof(dp));
        reverse(rating.begin(),rating.end());
        ans+=solve(rating,0,3,-1);
        return ans;
    }
};