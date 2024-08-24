class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>&dp,vector<int>&nums1,vector<int>&nums2){
        if(i>=nums1.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<nums1.size();k++){
            if((j&(1<<k))==0){
                ans=min(ans,(nums1[i]^nums2[k])+solve(i+1,((j)|(1<<k)),dp,nums1,nums2));
            }
        }
        return dp[i][j]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>((1<<nums1.size()),-1));
        return solve(0,0,dp,nums1,nums2);
    }
};