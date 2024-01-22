class Solution {
public:
    vector<int> solve(vector<int>&nums,int s,int e,int offset)
    {
        vector<int> res;
        int n=e-s+1;
        for(int i=0;i<(1<<n);i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    sum+=nums[j+offset];
            }
            res.push_back(sum);
        }
        return res;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        if(n==1)return min(abs(goal),abs(nums[0]-goal));
        vector<int> left=solve(nums,0,(n/2)-1,0);
        vector<int> right=solve(nums,n/2,n-1,n/2);
        sort(right.begin(),right.end());
        int ans=INT_MAX;
        for(int i=0;i<left.size();i++)
        {
            int x=left[i];
            auto it=lower_bound(right.begin(),right.end(),goal-x)-right.begin();
            if(it>0)
                ans=min(ans,abs(goal-x-right[it-1]));
            if(it<right.size())
                ans=min(ans,abs(goal-x-right[it]));
        }
        return ans;
    }
};