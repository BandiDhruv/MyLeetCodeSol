class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left=0,n=nums.size(),temp=0,ans=INT_MAX;
        vector<int>bit(32,0);
        for(int right=0;right<n;right++){
            temp|= nums[right];
            for(int k=0;k<32;k++){
                if(nums[right]&(1<<k)){
                    bit[k]++;
                }
            }
            while(temp>=k && left<=right){
                ans=min(ans,right-left+1);
                for(int k=0;k<32;k++){
                    if(nums[left]&(1<<k)){
                        bit[k]--;
                        if(bit[k]==0)temp^=(1<<k);
                    }
                }
                left++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};