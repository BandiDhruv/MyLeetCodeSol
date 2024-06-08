class Solution {
public:
    int  mp[501][502][28];
    int solve(vector<int>& nums, int k, int i, int last) {
        if(k==-1)return -1;
        if(i == nums.size())
            return 0;
        if (mp[i][last+1][k]!=-1)
            return mp[i][1+last][k];
        int take =0,nottake=0;
        if (last==-1 || nums[i] == nums[last])
            take = 1 + solve(nums, k, i + 1, i);
        else if(nums[i]!=nums[last])take=1+solve(nums,k-1,i+1,i);
        nottake = solve(nums, k, i + 1, last);
        return mp[i][last+1][k] = max(take, nottake);
    }

    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        memset(mp,-1,sizeof(mp));
        // vector<vector<vector<int>>> mp(n+1,vector<vector<int>>(n+1,vector<int>(k+2,-1)));
        return solve(nums, k, 0, -1);
    }
};