class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool ok=false;
        for(auto &it:nums){
            if(it==1)ok=true;
            if(it<=0 || it>n)it=1;
        }
        if(!ok)return 1;
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(val==n)nums[0]=-abs(nums[0]);
            else nums[val]=-abs(nums[val]);
        }
        for(int i=1;i<n;i++)if(nums[i]>0)return i;
        if(nums[0]>0)return n;
        return n+1;
    }
};