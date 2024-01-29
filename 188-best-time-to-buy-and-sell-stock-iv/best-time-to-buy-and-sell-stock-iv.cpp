class Solution {
public:
    int solve(int k,vector<int>&prices,int idx,int buy,vector<vector<vector<int>>> &dp)
    {
        if(idx>=prices.size() || k==0)
            return 0;
        if(dp[idx][k][buy]!=-1)return dp[idx][k][buy];
        int ans=INT_MIN;
        if(buy==0)
        {
            ans=max(-prices[idx]+solve(k,prices,idx+1,1,dp),solve(k,prices,idx+1,buy,dp));
        }
        else{
            ans=max(+prices[idx]+solve(k-1,prices,idx+1,0,dp),solve(k,prices,idx+1,buy,dp));
        }
        return dp[idx][k][buy]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(k,prices,0,0,dp);
    }
};