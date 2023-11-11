class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1,ans=0,m=1e9+7;
        vector<int> power(nums.size());
        power[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            power[i]=(power[i-1]*2)%m;
        }
        while(l<=r){
        if(nums[l]+nums[r]<=target)
        {
            ans=(ans%m+power[r-l])%m;
            l++;
        }
        else
            r--;
        }
        return ans;
    }

};