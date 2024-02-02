class Solution {
public:
    // int solve(vector<int>&nums,int i,int prev,vector<vector<int>> &dp)
    // {
    //     if(i>=nums.size())return 0;
    //     if( dp[i][prev+1]!=-1)return dp[i][prev+1];
    //     int take=0;
    //     int nottake=0;
    //     if(prev==-1 || ( nums[i]>nums[prev]))
    //     {
    //         take=1+solve(nums,i+1,i,dp);
    //     }
    //     nottake=solve(nums,i+1,prev,dp);
    //     return dp[i][prev+1]=max(take,nottake);
    // }   
    int lengthOfLIS(vector<int>& nums) {
        // vector<int>dp(nums.size()+1,1);
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=0;j<i;j++)
        //     {
        //         if(nums[i]>nums[j])
        //             dp[i]=max(dp[i],1+dp[j]);
                
        //     }
        //     maxi=max(maxi,dp[i]);
        // }
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
            }
            else{
                auto it=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[it]=nums[i];
            }
        }

        return temp.size();
    }
};