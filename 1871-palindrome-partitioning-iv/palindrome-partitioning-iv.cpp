class Solution {
public:
    int t[2001][2001];
    bool isPallindrome(int i,int j,string &s){
        if(t[i][j]!=-1)return t[i][j];
        int p=i,q=j;
        while(i<=j){
            if(s[i]!=s[j])return t[p][q]=false;
            i++;
            j--;
        }
        return t[p][q]=true;
    }

    int solve(string &s,int i,int k,vector<vector<int>>&dp){
        if(i>=s.size()){
            return k==0;
        }
        if(k<0)return false;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=0;
        for(int j=i;j<s.size();j++){
            if(isPallindrome(i,j,s)){
                ans=ans or solve(s,j+1,k-1,dp);
            }
        }
        return dp[i][k]=ans;
    }

    bool checkPartitioning(string s) {
        memset(t,-1,sizeof(t));
        vector<vector<int>> dp(s.size()+1,vector<int>(4,-1));
        return solve(s,0,3,dp);
    }
};