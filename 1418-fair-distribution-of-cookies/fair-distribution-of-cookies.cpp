class Solution {
public:
    
    int solve(int i,vector<int>&cookies,int k,vector<int>&sum/*,vector<vector<int>>&dp*/){
        if(i==cookies.size()){
            int ans=INT_MIN;
            for(auto it:sum)
                ans=max(ans,it);
            return ans;
        }
        // if(dp[i][j]!=-1)
            // return dp[i][j];
        int res=INT_MAX;
        // for(int p=0;p<cookies.size();p++){
            for(int q=0;q<k;q++){
                // if((j & (1<<p))==0){
                    sum[q]+=cookies[i];
                    res=min(res,solve(i+1,cookies,k,sum/*,dp*/));
                    sum[q]-=cookies[i];
                }
            // }
        // }
        return res;
        /*dp[i][j]=*/
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> s(k,0);
        // vector<vector<int>> dp(cookies.size()+1,vector<int>((1<<cookies.size()+1),-1));
        return solve(0,cookies,k,s/*,dp*/);
    }
};