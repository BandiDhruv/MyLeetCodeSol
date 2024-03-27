class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,right=0,n=nums.size(),pro=1,cnt=0,sum=0;
        while(right<n && left<n){
            pro*=nums[right];
            cout<<nums[right]<<" ";
            if(pro<k){
                cnt+=(right-left+1);
                right++;
            }
            else{
                pro/=nums[left];
                pro/=nums[right];
                if(pro==0)pro++;
                left++;
                if(left>right)right=left;
            }
        }
        return cnt;
    }
};