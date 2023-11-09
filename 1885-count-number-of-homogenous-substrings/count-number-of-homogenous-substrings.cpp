class Solution {
public:
    // int solve(string s,int idx){
    //     if(idx>=s.size())
    //         return 0;
    //     int count=0;
    //     for(int i=idx+1;i<s.size();i++)
    //     {   
    //         string temp=s.substr(idx,i);

    //     }
    // }
    int countHomogenous(string s) {
        int m=1e9+7;
        int length=0,res=0;
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1])
                length+=1;
            else
                length=1;
            res=(res+length)%m;
        }
        return res;
    }
};