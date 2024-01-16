class Solution {
public:

    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<n;i++)
        {
            int curr=arr[i];
            int prev=arr[i]-d;
            if(mp.find(prev)!=mp.end())
                mp[curr]=1+mp[prev];
            else mp[curr]=1;
            res=max(mp[curr],res);
        }
        return res;
    }
};