class Solution {
public:
    int t[33][3][3];
    int solve(int n,int i,int f,int prev){
        if(i==32)
            return 1;
        if(t[i][f][prev]!=-1)
            return t[i][f][prev];
        int ans=0;
        int ub=f?(n>>(31-i))&1:1;
        for(int k=0;k<=ub;k++){
            if(k && prev)
                continue;
            ans+=solve(n,i+1,f&(k==ub),k==1);
        }
        return t[i][f][prev]=ans;
    }
    string DecimalToBinary(int num)
    {
        string str;
        while(num){
            if(num & 1) // 1
                str+='1';
            else // 0
                str+='0';
            num>>=1; // Right Shift by 1  
        }    
        reverse(str.begin(),str.end());
        return str;
    }
    int findIntegers(int n) {
        // string temp=DecimalToBinary(n);
        memset(t,-1,sizeof(t));
        return solve(n,0,1,0);        
    }
};