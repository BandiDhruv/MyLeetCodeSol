class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,cnt=1,ans=0;
        for(int right=0;right<nums.size();right++){
            cnt*=nums[right];
            while(cnt>=k && left<=right){
                cnt/=nums[left];
                left++;
                if(cnt==0)cnt=1;
            }

            ans+=(right-left+1);
        }
        return ans;
    }
};