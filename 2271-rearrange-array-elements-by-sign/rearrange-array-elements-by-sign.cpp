class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> p,ne;
        for(auto &it:nums)
        {
            if(it>0)p.push_back(it);
            else ne.push_back(it);
        }
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(i&1) nums[i]=ne[j++];
            else nums[i]=p[k++];
        }
        return nums;
    }
};