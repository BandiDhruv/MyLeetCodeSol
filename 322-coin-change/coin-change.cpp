class Solution {
public:
    int solve(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp)
    {
        if(idx>=coins.size())
        {
            return 1e9;
        }
        if(amount<0)return 1e9;
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        if(amount==0)return 0;      

        int take=1+solve(coins,amount-coins[idx],idx,dp);
        int nottake=solve(coins,amount,idx+1,dp);
        return dp[idx][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(coins,amount,0,dp)==1e9?-1:solve(coins,amount,0,dp);
    }
};