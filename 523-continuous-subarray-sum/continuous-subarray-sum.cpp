class Solution {
public:
    int n;
    bool checkSubarraySum(vector<int>& nums, int k) {
        n=nums.size();
        map<int,int> mp;
        long long sum=0;
        mp[0]=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum%k)==mp.end())
                mp[sum%k]=i+1;
            else if(mp[sum%k]<i)return true;
        }
        return false;
    }
};