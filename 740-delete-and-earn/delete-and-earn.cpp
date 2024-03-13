class Solution {
public:
    int solve(vector<int>&mp,int idx,vector<int>&dp)
    {
        if(idx>=mp.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        return dp[idx]=max(solve(mp,idx+1,dp),solve(mp,idx+2,dp)+mp[idx]*idx);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(10001,0);
        vector<int> dp(10005,-1);
        for(int i=0;i<nums.size();i++)freq[nums[i]]++;
        return solve(freq,0,dp);
    }
};