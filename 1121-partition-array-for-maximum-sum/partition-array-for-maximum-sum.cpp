class Solution {
public:
    int mod=1e9+7;
    int solve(vector<int>&arr,int k,int idx,vector<int>&dp)
    {
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int ans=0;
        int curmax=-1;
        int n=arr.size();
        int size=min(n,idx+k);
        for(int i=idx;i<size;i++)
        {
            curmax=max(curmax,arr[i]);
            ans=max(ans,(curmax*(i-idx+1)+solve(arr,k,i+1,dp)));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,k,0,dp);
    }
};