class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            ans=max(ans,nums[i]+nums[j]);
            i++;j--;
        }
        return ans;
    }
};