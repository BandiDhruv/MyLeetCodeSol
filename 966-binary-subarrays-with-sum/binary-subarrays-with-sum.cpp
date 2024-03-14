class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> pre(nums.size());
        pre[0]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
               sum+=nums[j];
               if(sum==goal)ans++;
            }
        }
        return ans;
    }
};