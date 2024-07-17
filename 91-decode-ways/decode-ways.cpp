class Solution {
public:
    int t[102];
    int solve(string &s,int i){
        if(i>=s.size())
            return 1;
        if(t[i]!=-1)return t[i];
        int option1=0;
        if(s[i]!='0')
            option1=solve(s,i+1);
        int option2=0;
        int option3=0;

        if(i+1<s.size() && (s[i]=='2' && (s[i+1]=='0' || s[i+1]=='1' || s[i+1]=='2' || s[i+1]=='4' || s[i+1]=='5' || s[i+1]=='6' || s[i+1]=='3')))
            option2=solve(s,i+2);
        if(i+1<s.size() && s[i]=='1')
            option3=solve(s,i+2);
        return t[i]=option1+option2+option3;
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        memset(t,-1,sizeof(t));
        return solve(s,0);
    }
};