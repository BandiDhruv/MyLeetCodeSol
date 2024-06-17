class Solution {
public:
    vector<int> pre;
    int solve(vector<int>&piles,int i,int m,int turn,vector<vector<vector<int>>> &dp){
        if(i>=piles.size())
            return 0;
        if(dp[i][m][turn]!=-1)return dp[i][m][turn];
        int ans=(turn)?0:INT_MAX;
        for(int j=1;j<=2*m;j++){
            if(j+i-1<piles.size()){
                if(turn){
                    ans=max(ans,pre[j+i-1]-((i>0)?pre[i-1]:0)+solve(piles,i+j,max(m,j),0,dp));
                }
                else{
                    ans=min(ans,solve(piles,i+j,max(m,j),1,dp));
                }
            }
        }
        return dp[i][m][turn]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int m=1;
        pre.resize(piles.size(),0);
        pre[0]=piles[0];
        for(int i=1;i<piles.size();i++){
            pre[i]=pre[i-1]+piles[i];
        }
        vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>>(101,vector<int>(2,-1)));
        return solve(piles,0,m,1,dp);
    }
};