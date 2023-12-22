class Solution {
public:
    int n,m;
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j)
    {
        if(i>=n || j>=m)
            return -1e8;
        // ye nahi soch paya saala bc bhag yrr 
        long long ans=max(nums1[i]*nums2[j],max(nums1[i]*nums2[j]+solve(nums1,nums2,i+1,j+1),max(solve(nums1,nums2,i+1,j),solve(nums1,nums2,i,j+1))));
        return ans;
    }
    int solvemem(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>> & dp)
    {
        if(i>=n || j>=m)
            return -1e8;
        if(dp[i][j]!=-1) return dp[i][j];
        // ye nahi soch paya saala bc bhag yrr 
        int ans=max(nums1[i]*nums2[j],max(nums1[i]*nums2[j]+solvemem(nums1,nums2,i+1,j+1,dp),max(solvemem(nums1,nums2,i+1,j,dp),solvemem(nums1,nums2,i,j+1,dp))));
        dp[i][j]=ans;
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        // return solve(nums1,nums2,0,0);
        return solvemem(nums1,nums2,0,0,dp);
    }
};