class Solution {
public:
    bool isP(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int cntModifications(int s,int e,string&st){
        int ans=0;
        while(s<=e){
            if(st[s]!=st[e])ans++;
            s++;e--;
        }
        return ans;
    }
    int solve(string &s,int k,int i,vector<vector<int>>&dp){
        if(i==s.size()){
            if(k==0){
                return 0;
            }
            return 1e8;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=1e8;
        for(int idx=i;idx<s.size();idx++){
            if(k-1>=0)
            ans=min(ans,cntModifications(i,idx,s)+solve(s,k-1,idx+1,dp));
        }
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size()+1,vector<int>(k+1,-1));
        return solve(s,k,0,dp);
    }
};