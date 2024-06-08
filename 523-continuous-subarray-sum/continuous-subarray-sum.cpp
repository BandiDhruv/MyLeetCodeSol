class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end())
                mp[sum%k]=i+1;
            else if(i-mp[sum%k]>0)return true;
        }
        return false;
    }
};