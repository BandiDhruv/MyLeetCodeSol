class Solution {
public:
    int solve(vector<int>&jd,int d,int idx,vector<vector<int>> &dp)
    {
        if(d==1)
        {
            int maxD=jd[idx];
            for(int i=idx;i<jd.size();i++)
                maxD=max(maxD,jd[i]);
            return maxD;
        }
        if(dp[idx][d]!=-1)return dp[idx][d];
        int maxD=jd[idx];
        int ans=INT_MAX;

        for(int i=idx;i<=jd.size()-d;i++)
        {
            maxD=max(maxD,jd[i]);
            ans=min(ans,maxD+solve(jd,d-1,i+1,dp));
        }
        return dp[idx][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)return -1;
        // return solve(jobDifficulty,d,0);
        vector<vector<int>> dp(jobDifficulty.size()+1,vector<int>(d+1,-1));
        return solve(jobDifficulty,d,0,dp);
    }
};