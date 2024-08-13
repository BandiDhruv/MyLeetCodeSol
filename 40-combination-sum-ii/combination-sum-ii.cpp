class Solution {
public:
    void solve(vector<int>&nums,int target,int i,set<vector<int>>&res,vector<int>&temp){
        if(target==0){
            res.insert(temp);
            return;
        }
        if(i>=nums.size() || target<0)
            return; 
        int j=i;
        while(j<nums.size() && nums[i]==nums[j])
            j++;
        solve(nums,target,j,res,temp);
        if(target-nums[i]>=0){
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],i+1,res,temp);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,res,temp);
        for(auto it:res)
            ans.push_back(it);
        return ans;
    }
};