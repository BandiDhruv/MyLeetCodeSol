class Solution {
public:
    bool check(string &a,string &b)
    {
        if(a.size()!=1+b.size())return false;
        int i=0,j=0;
        while(i<a.size())
        {
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        // cout<<i<<" "<<j<< " "<<a.size()<<" "<<b.size()<<endl;
        return (i==a.size() && j==b.size());
    }
    bool static cmp(string &s1,string &s2)
    {
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(words.size()+1,1);
        int maxi=INT_MIN;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                // cout<<check(words[i],words[j])<<endl;
                if(check(words[i],words[j]))
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};