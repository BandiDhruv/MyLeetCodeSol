class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, n = nums.size();
        int sum = 0, ans = -1;
        map<int, int> mp;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            mp[nums[r]]++;
            while (l <= r && mp[nums[r]] > 1){
                // ans = max(ans, sum);
                sum -= nums[l];
                mp[nums[l++]]--;
            }
            ans = max(ans,sum);
        }
        ans = max(ans, sum);
        return ans;
    }
};