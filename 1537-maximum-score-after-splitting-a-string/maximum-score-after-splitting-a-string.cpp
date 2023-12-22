class Solution {
public:
    int maxScore(string s) {
        int one=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')one++;
        }
        int zero=0;
        int res=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='1')one--;
            else zero++;
            res=max(res,zero+one);
        }
        return res;
    }
};