class Solution {
public:
    int solve(int mid,vector<int>&nums){
        long long left=0;
        long long ans=0;
        for(long long right=0;right<nums.size();right++){
            while(nums[right]-nums[left]>mid && left<=right){
                left++;
            }
            ans+=(right-left);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums[nums.size()-1]-nums[0];
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(solve(mid,nums)<k){
                lo=mid+1;
            }
            else {
                hi=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};