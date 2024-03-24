class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans(nums.size(),0);
        map<int,long long> mp;
        set<pair<long long , int>> st;
        for(int i=0;i<nums.size();i++){
            int x=nums[i],y=freq[i];
            auto &it=mp[x];
            st.erase({it,nums[i]});
            st.insert({it+y,nums[i]});
            it+=y;
            ans[i]=st.rbegin()->first;
            if(ans[i]<0)ans[i]=0;
        }
        return ans;
        
    }
};