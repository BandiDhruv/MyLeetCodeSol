class Solution {
public:
    int mod=1e9+7;
    int t[10000+2][6][12][12];

    int solve(int i,int n,string &s,int cnt,int first,int last){
        if(i==n)
            return t[i][cnt][first+1][last+1] = (cnt == 5)?1:0;
        if(t[i][cnt][first+1][last+1]!=-1)
            return t[i][cnt][first+1][last+1]%mod;
        int ans=0;
        int ans2=solve(i+1,n,s,cnt,first,last)%mod;
        // if(cnt==5)ans=(solve(i+1,n,s,cnt,first,last))%mod;
        if(cnt==4 && s[i]-'0'==first){ans=(solve(i+1,n,s,cnt+1,first,last))%mod;}
        if(cnt==3 && s[i]-'0'==last){ans=(solve(i+1,n,s,cnt+1,first,last))%mod;}
        if(cnt==2){ans=(solve(i+1,n,s,cnt+1,first,last))%mod;}
        if(cnt==1){ans=(solve(i+1,n,s,cnt+1,first,s[i]-'0'))%mod;}
        if(cnt==0){ans=(solve(i+1,n,s,cnt+1,s[i]-'0',last))%mod;}
        return t[i][cnt][first+1][last+1]=(ans%mod+ans2%mod)%mod;

    }

    int countPalindromes(string s) {
        memset(t,-1,sizeof(t));      
        return solve(0,s.size(),s,0,-1,-1)%mod;    
    }
};