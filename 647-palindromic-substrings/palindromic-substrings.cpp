class Solution {
public:
    int solve(string &s,int i,int j)
    {
        if(i>j)return 1;
        if(s[i]==s[j])
        {
            return solve(s,i+1,j-1);
        }
        return 0;
    }

    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ans+=solve(s,i,j);
            }
        }
        return ans;
    }
};