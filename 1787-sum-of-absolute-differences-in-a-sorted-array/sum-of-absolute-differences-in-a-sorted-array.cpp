class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>res;
        vector<int> pre(nums.size()),suf(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        suf[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            cout<<i<<" s-> "<<suf[i]<<" p-> "<<pre[i]<<endl;
        }
        for(int i=0;i<nums.size();i++)
        {
            int ans=((nums[i]*i)-pre[i])+(suf[i]-(nums[i]*(nums.size()-1-i)));
            res.push_back(ans);
        }
        return res;
    }
};