class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        vector<int> dp(2e4+1);
        dp[0]=0;
        dp[1]=mp[1];
        for(int i=2;i<=2e4;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+mp[i]*i);
        }
        return dp[2e4];
    }
};