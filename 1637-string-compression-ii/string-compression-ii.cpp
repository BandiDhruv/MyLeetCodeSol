    // int dp[101][27][101][101];
class Solution {
public:
    int t[101][101];
    // int solve(string s,int idx,int prev,int freq,int k)
    // {
    //     if(k<0)
    //         return INT_MAX;
    //     if(idx>=s.size())
    //         return 0;
    //     int del=solve(s,idx+1,prev,freq,k-1);
    //     int take=0;
    //         if(s[idx]-'a'!=prev)
    //     {
    //         take= 1 + solve(s,idx+1,s[idx]-'a',1,k);
    //     }
    //     else
    //     {
    //         int no=0;
    //         if(freq==1 || freq==9 || freq==99)
    //         {
    //             no=1;
    //         }
    //         take=no+solve(s,idx+1,prev,freq+1,k);
    //     }
    //     return min(del,take);
    // }
    // int solvemem(string s,int idx,int prev,int freq,int k)
    // {
    //     if(k<0)
    //         return 1e9;
    //     if(idx>=s.size())
    //         return 0;
    //     if(dp[idx][prev][freq][k]!=-1)
    //      return dp[idx][prev][freq][k]; 
    //     int del=solvemem(s,idx+1,prev,freq,k-1);
    //     int take=0;
    //         if(s[idx]-'a'!=prev)
    //     {
    //         take= 1 + solvemem(s,idx+1,s[idx]-'a',1,k);
    //     }
    //     else
    //     {
    //         int no=0;
    //         if(freq==1 || freq==9 || freq==99)
    //         {
    //             no=1;
    //         }
    //         take=no+solvemem(s,idx+1,prev,freq+1,k);
    //     }
    //     return dp[idx][prev][freq][k]=min(del,take);
    // }
    int solve2d(int idx,int k,string s)
    {
        if(k<0)return 1e9;
        if(idx>=s.size()||(s.size()-idx)<=k) return 0;
        if(t[idx][k]!=-1) return t[idx][k];
        int del=solve2d(idx+1,k-1,s);
        int keep=1e9,deleted=0,freq=0,addition=0;
        for(int j=idx;j<s.size() && deleted<=k;j++)
        {
            if(s[j]==s[idx])
            {
                freq++;
                if(freq==2 || freq==10 || freq==100) addition++;
            }
            else deleted++;
            keep=min(keep,1+addition+solve2d(j+1,k-deleted,s));
        }
        return t[idx][k]=min(keep,del);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        // return solve(s,0,26,0,k);
        //idx prev freq k
        // vector<vector<vector<vector<int>>>> dp(s.size()+1,vector<vector<vector<int>>>(27,vector<vector<int>>(s.size()+1,vector<int>(s.size()+1,-1))));
        // memset(dp,-1,sizeof(dp));
        // return solvemem(s,0,26,0,k);
        memset(t,-1,sizeof(t));
        return solve2d(0,k,s);
    }
};