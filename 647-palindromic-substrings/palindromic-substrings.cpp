class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            cnt++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                cnt+=dp[i][i+1];
            }
        }
        // for(auto it:dp){
        //     for(auto i:it)cout<<i<<" ";
        //     cout<<endl;
        // }
        for(int len=3;len<=n;len++){
            for(int i=0,j=len-1;j<n;j++,i++){
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                cnt+=dp[i][j];
            }
        }
        // for(auto it:dp){
        //     for(auto i:it)cout<<i<<" ";
        //     cout<<endl;
        // }
        return cnt;
    }
};