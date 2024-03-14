class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        // mp[0]=0;
        int sum=0;
        int ans=0;
        for(auto it:nums)
        {
            sum+=it;
            if(sum==goal)ans++;
            if(mp.find(sum-goal)!=mp.end())ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};