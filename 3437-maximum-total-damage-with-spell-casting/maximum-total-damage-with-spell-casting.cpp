class Solution {
public:
    long long dp[100001][6];
    long long solve(vector<pair<int,int>>& v,int idx,int j,int n){
        if(idx>=n)return 0;
        if(dp[idx][j]!=-1)return dp[idx][j];
        long long ans=0;
        if(j==0){
            ans=max(ans,1ll*v[idx].first*v[idx].second+solve(v,idx+1,1,n));
            ans=max(ans,solve(v,idx+1,0,n));
        }
        else{
            if(abs(v[idx-j].first-v[idx].first)>2)
                ans=max(ans,1ll*v[idx].first*v[idx].second+solve(v,idx+1,1,n));
            if(j<=4)ans=max(ans,solve(v,idx+1,j+1,n));
        }
        return dp[idx][j]=ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int> m;
        for(auto &it : power) m[it]++;
        vector<pair<int,int>> v(m.begin(),m.end());
        int n=v.size();
        memset(dp,-1,sizeof(dp));
        return solve(v,0,0,n);
    }
};