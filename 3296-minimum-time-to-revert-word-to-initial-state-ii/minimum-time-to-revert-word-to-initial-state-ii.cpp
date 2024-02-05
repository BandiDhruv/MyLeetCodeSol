class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        vector<int> lps(s.length(),0);
        int i=0,j=1;
        //THIS LPS APPROACH FROM AANCHAL VIDEO ->https://www.youtube.com/watch?v=sy-jwlCETfw&t=778s
        while(j<s.length())
        {
            if(s[i]==s[j])
            {
                i++;
                lps[j]=i;
                j++;
            }
            else
            {
                if(i==0)
                    j++;
                else
                    i=lps[i-1];
            }
        }
        int n=s.size();
        int ml=lps[n-1];
        while(ml>0 && (n-ml)%k!=0)
        {
            ml=lps[ml-1];
        }
        if((n-ml)%k==0)return (n-ml)/k;
        return (n+k-1)/k;
    }
};