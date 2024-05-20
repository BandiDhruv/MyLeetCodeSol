class Solution {
public:
    int p=0,n;
    void solve(vector<int>&nums,int idx,int t){
        if(idx>=n)return ;
        solve(nums,idx+1,t);
        t^=nums[idx];
        solve(nums,idx+1,t);
        p+=t;
    }
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        solve(nums,0,0);
        return p;
    }
};