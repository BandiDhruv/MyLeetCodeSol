class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,deque<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_front(nums[i][j]);
            }
        }
        for(auto it:mp)
        {
            for(auto i:it.second)
                // cout<<i<<"->";
                ans.push_back(i);
            // cout<<endl;
        }
        // reverse(ans.begin(),ans.end());
        return ans;// 00 10 01 20 11 02   
    }
};