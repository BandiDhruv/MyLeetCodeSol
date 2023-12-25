class Solution {
public:
    int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hfences, vector<int>& vfences) {
        // if(m==n) return (m-1)*(m-1);
        unordered_set<int> s1,s2;
        hfences.push_back(1);
        hfences.push_back(m);
        vfences.push_back(1);
        vfences.push_back(n);
        sort(hfences.begin(),hfences.end());
        sort(vfences.begin(),vfences.end());
        for(int i=0;i<hfences.size()-1;i++)
        {
            for(int j=i+1;j<hfences.size();j++)
            {
                s1.insert(hfences[j]-hfences[i]);
            }
        }
        for(int i=0;i<vfences.size()-1;i++)
        {
            for(int j=i+1;j<vfences.size();j++)
            {
                s2.insert(vfences[j]-vfences[i]);
            }
        }
        long long ans=0;
        for(auto it:s1)
        {
            if(s2.find(it)!=s2.end())
            {
                long long k=(long long)it*it;
                if(k>ans)
                {
                    ans=k;
                }
            }
        }

        if(ans==0) return -1;
        ans=ans%mod;
        return ans;
    }
};