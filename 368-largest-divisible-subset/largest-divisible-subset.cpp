class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1,1);
        vector<int> hash(nums.size());
        int maxi=0,last=-1;
        for(int i=0;i<nums.size();i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int> ans;
        // int idx=hash[]
        while(maxi--)
        {
            ans.push_back(nums[last]);
            last=hash[last];
        }
        return ans;
    }
};