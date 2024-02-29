class Solution {
public:
    bool check(string &a,string &b)
    {
        if(a.size()!=b.size()+1)return false;
        int i=0,j=0;
        for(;i<a.size();i++)
        {
            if(a[i]==b[j])j++;
        }
        return i==a.size() and j==b.size();
    }
    bool static cmp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),cmp);
        vector<int> dp(w.size()+1,1);
        int maxi=-1;
        for(int i=0;i<w.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(w[i],w[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};