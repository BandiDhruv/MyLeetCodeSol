class Solution {
public:
    typedef long long ll;
    //prev-0-pos-1-neg
    ll t[100002][3][3];
    ll solve(vector<int>&nums,int i,ll isStart,ll sign){
        if(i>=nums.size())return 0;
        if(t[i][isStart][sign]!=-1)return t[i][isStart][sign];
        ll nottake=nums[i]+solve(nums,i+1,1,1);
        ll take=(sign==0)?nums[i]:-nums[i]+solve(nums,i+1,1,1-sign);
        return t[i][isStart][sign] = max(take,nottake);
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};