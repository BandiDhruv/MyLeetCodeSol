class Solution {
public:
    set<vector<int>> set;
    void solve(vector<int>&nums,vector<int>temp,int idx)
    {
        if(idx==nums.size())
        {
            sort(temp.begin(),temp.end());
            set.insert(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(nums,temp,idx+1);
        temp.pop_back();
        solve(nums,temp,idx+1);
        // set.push(temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp,0);
        vector<vector<int>> ans;
        for(auto a:set)
        {
            ans.push_back(a);
        }
        return ans;
    }
};