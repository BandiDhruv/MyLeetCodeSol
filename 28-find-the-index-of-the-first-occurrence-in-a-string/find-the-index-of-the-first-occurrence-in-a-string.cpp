class Solution {
public:
    int strStr(string s, string t) {
        int slen=s.length(),tlen=t.length();
        vector<int> lps(tlen,0);
        int prevInd=0,i=1,j;
        while(i<tlen)
        {
            if(t[i]==t[prevInd])
            {
                prevInd++;
                lps[i]=prevInd;
                i++;
            }
            else
            {
                if(prevInd==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    prevInd=lps[prevInd-1];
                }
            }
        }
        i=0,j=0;
        while(i<slen)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)i++;
                else j=lps[j-1];
            }
            if(j==tlen)return(i-tlen);
        }
        return -1;
    }
};