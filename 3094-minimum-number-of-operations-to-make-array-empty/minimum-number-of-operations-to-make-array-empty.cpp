class Solution {
public:
    int minOperations(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==1)return -1;
            ans+=ceil((double)(it.second)/3);
        }
        return ans;
    }
};