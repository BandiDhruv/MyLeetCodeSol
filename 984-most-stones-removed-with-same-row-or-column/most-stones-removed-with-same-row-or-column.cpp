class DisjointSet
{
public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node)
    {
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)return ;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mr=-1,mc=-1;
        for(auto it:stones)
        {
            mr=max(mr,it[0]);
            mc=max(mc,it[1]);
        }
        DisjointSet ds(mr+mc+1);
        unordered_map<int,int> mp;  

        for(auto it:stones)
        {
            int noderow=it[0];
            int nodecol=it[1]+mr+1;
            ds.unionBySize(noderow,nodecol);
            mp[noderow]=1;
            mp[nodecol]=1;
        }
        int cnt=0;
        for(auto it:mp)
        {
            if(ds.findUpar(it.first)==it.first)
            {
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};