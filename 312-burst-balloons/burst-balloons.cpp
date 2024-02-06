class Solution {
public:
int n;
    // int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        
    //     if(i>j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int maxi=-1e9;
    //     for(int idx=i;idx<=j;idx++)
    //     {
    //         int cost=nums[i-1]*nums[idx]*nums[j+1]+solve(nums,i,idx-1,dp)+solve(nums,idx+1,j,dp);
    //         maxi=max(maxi,cost);
    //     }
    //     return dp[i][j]=maxi;
    // }

    int maxCoins(vector<int>& nums) {
        n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int idx=i;idx<=j;idx++)
                {
                    int cost=nums[i-1]*nums[idx]*nums[j+1]+dp[i][idx-1]+dp[idx+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};