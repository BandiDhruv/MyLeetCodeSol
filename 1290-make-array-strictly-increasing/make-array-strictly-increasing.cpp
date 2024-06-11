class Solution {
public:
    int solve(int i,int prev,vector<int>&arr1,vector<int>&arr2,map<int,map<int,int>> &mp){
        if(i==arr1.size())return 0;
        int ans=10001;
        if(mp.find(i)!=mp.end() && mp[i].find(prev)!=mp[i].end())return mp[i][prev];
        if(arr1[i]>prev)
            ans=min(ans,solve(i+1,arr1[i],arr1,arr2,mp));
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it!=end(arr2))
            ans=min(ans,1+solve(i+1,*it,arr1,arr2,mp));
        return mp[i][prev]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<int,map<int,int>> mp;
        return solve(0,-1,arr1,arr2,mp)==10001?-1:solve(0,-1,arr1,arr2,mp);
    }
};