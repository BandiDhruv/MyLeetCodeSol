class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)
            return ;
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else {
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    void unionBySize(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)
            return ;
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
            size[pu]+=size[pv];
        }
        else 
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        DisjointSet ds(isConnected.size());
        // vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(ds.findUpar(i)==i)
                ans++;
        }
        return ans;
    }
};