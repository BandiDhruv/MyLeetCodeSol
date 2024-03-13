class Solution {
public:
    static bool cmp(const pair<int,long long>&a,const pair<int,long long> &b)
    {
        if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    }
    int edgeScore(vector<int>& edges) {
        map<int,long long> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i]]+=1ll*i;
        }
        vector<pair<int,long long>> vp(mp.begin(),mp.end());
        sort(vp.begin(),vp.end(),cmp);
        for(auto it:vp)cout<<it.first<<" "<<it.second<<endl;
        return (int)vp[0].first;
    }
};