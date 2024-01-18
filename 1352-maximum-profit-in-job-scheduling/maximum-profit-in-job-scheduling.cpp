class Solution {
public:
    int n;
    int solve(vector<vector<int>> &vp,int idx,vector<int>&dp)
    {
        if(idx>=n || idx<0) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int take=0,nottake=0;
        auto it = lower_bound(vp.begin(),vp.end(),vp[idx][1],[](const vector<int>&a,int val){return a[0]<val;});
        take += vp[idx][2] + solve(vp, distance(vp.begin(), it),dp);
        nottake+=solve(vp,idx+1,dp);
        return dp[idx]=max(take,nottake);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> vp;
        n=s.size();
        if(n==1)return p[0];
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(s[i]);
            temp.push_back(e[i]);
            temp.push_back(p[i]);
            vp.push_back(temp);
        }
        sort(vp.begin(),vp.end());
        vector<int> dp(n+1,-1);
        return solve(vp,0,dp);
    }
};