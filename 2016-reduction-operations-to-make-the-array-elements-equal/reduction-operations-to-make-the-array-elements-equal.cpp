class Solution {
public:
    int fac(int n)
    {
        if(n==1 || n==0)
            return 1;
        return n*fac(n-1);
    }
    int solve(int n)
    {
        return n*(n-1)/2;
    }
    int reductionOperations(vector<int>& nums) {
        // int maxidx=0;
        // int maxele=nums[0];
        // for(int i=1;i<nums.size();i++)
        // {
        //     if(nums[i]>maxele)
        //     {
        //         maxele=nums[i];
        //         maxidx=i;
        //     }
        // }
        // int ans=0;
        sort(nums.begin(),nums.end());
        int ans=0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        set<int> set(nums.begin(),nums.end());
        if(nums.size()==set.size())
        {
            if(nums.size()==1)
                return 0;
            // return solve(nums.size());
        }
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i]!=nums[i-1])
            {
                ans+=freq[nums[i]];
                freq[nums[i-1]]+=freq[nums[i]];
                // nums[i]=nums[i-1];
            }
        }
        return ans;
    }
};