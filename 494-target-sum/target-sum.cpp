class Solution {
public:
    int solve(vector<int>&nums,int tar,int i){
        if(i>=nums.size())return tar==0;
        int op1=solve(nums,tar+nums[i],i+1);
        int op2=solve(nums,tar-nums[i],i+1);
        return op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0);
    }
};