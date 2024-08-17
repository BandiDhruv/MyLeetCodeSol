class Solution {
public:
    int mod=1e9+7;
    int dp[2002][53][53];
    int solve(vector<int>&nums,int i,int prev1,int prev2){
        if(i>=nums.size())
            return 1;
        if(dp[i][prev1+1][prev2+1]!=-1)
            return dp[i][prev1+1][prev2+1];
        int ans=0;
        for(int idx=0;idx<=nums[i];idx++){
            if(idx>=prev1 && (nums[i]-idx)<=prev2){
                ans+=solve(nums,i+1,idx,nums[i]-idx);
                ans%=mod;
            }
        }
        return dp[i][prev1+1][prev2+1]=ans;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,51);
    }
};