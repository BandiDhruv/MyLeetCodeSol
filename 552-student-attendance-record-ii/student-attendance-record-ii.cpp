class Solution {
public:
    int mod=1e9+7;
    long long t[100001][4][3];
    long long solve(int n,int l,int a)
    {
        if(l>=3|| a>=2 || n<0)
            return 0;
        if(n==0)
        {
            return 1;
        }
        if(t[n][l][a]!=-1)return t[n][l][a];
        long long ans=(solve(n-1,l+1,a)%mod+solve(n-1,0,a+1)%mod+solve(n-1,0,a)%mod)%mod;
        return t[n][l][a]=ans;
    }
    int checkRecord(int n) {
        int l=0,a=0,p=0;
        memset(t,-1,sizeof(t));
        return (int)solve(n,l,a)%mod;    
    }
};