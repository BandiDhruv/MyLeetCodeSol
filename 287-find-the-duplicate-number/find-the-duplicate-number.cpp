class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int slow=nums[0],fast=nums[0];
        // do{
        //     slow=nums[slow];
        //     fast=nums[nums[fast]];
        // }while(slow!=fast);
        
        // fast=nums[0];
        // while(slow!=fast)
        // {
        //     slow=nums[slow];
        //     fast=nums[fast];
        // }   
        // return slow;
        int n=nums.size(),ans;
        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(nums[ind]>0)
                nums[ind]=-1*nums[ind];
            else ans=abs(nums[i]);
        }
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]>0)
        //         return nums[i];
        // }
        return ans;
    }
};