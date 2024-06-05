class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long> pre(nums.size());
        sort(nums.begin(),nums.end());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            pre[i]=pre[i-1]+nums[i];
        long long ans=-1;
        for(int i=nums.size()-1;i>=2;i--){
            long long temp=pre[i-1];
            if(temp>nums[i]){
                ans=pre[i];
                break;
            }
        }
        return ans;
    }
};