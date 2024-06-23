class Solution {
public:

    int solve(vector<int>&arr,int i,int sign,vector<vector<int>>& dp){
        if(i>=arr.size()-1)return 0;
        if(dp[i][sign]!=-1)return dp[i][sign];
        int cnt=0;
        if(sign==0){
            if(arr[i]>arr[i+1]){
                cnt=1+solve(arr,i+1,1-sign,dp);
            }
        }
        if(sign==1){
            if(arr[i]<arr[i+1]){
                cnt=1+solve(arr,i+1,1-sign,dp);
            }
        }
        return dp[i][sign]=cnt;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=INT_MIN;
        vector<vector<int>> dp(arr.size()+1,vector<int>(3,-1));
        for(int i=0;i<arr.size();i++){
            ans=max(ans,1+max(solve(arr,i,0,dp),solve(arr,i,1,dp)));
        }
        return ans;
    }
};