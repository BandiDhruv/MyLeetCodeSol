class Solution {
public:
    int solve(vector<int>&nums,int k){
        int left=0,n=nums.size(),ans=0;
        vector<int> mp(2,0);
        for(int right=0;right<n;right++){
            mp[nums[right]%2]++;
            while(mp[1]>k && left<=right){
                mp[nums[left]%2]--;
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};