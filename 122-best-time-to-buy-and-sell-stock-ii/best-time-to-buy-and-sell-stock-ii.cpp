class Solution {
public:
    int solve(vector<int>&p,int idx,bool f,vector<vector<int>>&dp)
    {
        if(idx>=p.size()){
            return  0;
        }
        if(dp[idx][f]!=-1)return dp[idx][f];
        int profit=0;
        if(f)
        {
            profit=max({profit-p[idx]+solve(p,idx+1,false,dp),profit,solve(p,idx+1,f,dp)});
        }
        else{
            profit=max({profit+p[idx]+solve(p,idx+1,true,dp),profit,solve(p,idx+1,f,dp)});
        }
        return dp[idx][f]=profit;
    }
    int maxProfit(vector<int>& prices) {
        bool f=true;
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,-1));
        return solve(prices,0,f,dp);
    }
};