class Solution {
public:
    int mod=1e9+7;
    int rev(int n)
    {
        int a=0;
        stack<int> st;
        while(n>0)
        {
            st.push(n%10);
            n=n/10;
        }
        long long int m=1;
        while(!st.empty())
        {
            int temp=m*st.top();
            m=m*10;
            a+=temp;
            st.pop();
        }
        return a;
    }
    int countNicePairs(vector<int>& nums) {
        long long int count=0;
        unordered_map<long long int,long long int> mp;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]-=rev(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            // if(mp.find(nums[i])!=mp.end())
            // {
            // }
                mp[nums[i]]++;
            // cout<<nums[i]<<endl;
        }
        for(auto it:mp)
        {
            // if(it.first!=0){
                count=(count+(it.second*(it.second-1))/2)%mod;
            // cout<<it.first<<"   ->>   "<<it.second;
            // }
        }
        return count;
    }
};