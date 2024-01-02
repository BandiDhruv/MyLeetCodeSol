class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        
        unordered_set<int> st(nums.begin(),nums.end());
        while(!st.empty())
        {
            vector<int> temp;
            for(auto it = st.begin(); it != st.end();)
            {
                if(mp[*it] > 0)
                {
                    mp[*it]--;
                    temp.push_back(*it);
                    if(mp[*it] == 0)
                    {
                        it = st.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
                else
                {
                    ++it;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};