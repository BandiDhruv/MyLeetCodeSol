class DisjointSet{
    vector<int> rank,size,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node)
    {
        if(node==parent[node])
            return node;
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
            size[pv]++;
        } 
        else
        {
            parent[pv]=pu;
            size[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(int i=0;i<connections.size();i++)
        {
            if(ds.findUpar(connections[i][0])==ds.findUpar(connections[i][1]))extra++;
            else
            ds.unionBySize(connections[i][0],connections[i][1]);
        }
        int notConnected=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findUpar(i)==i)notConnected++;
        }
        int req=notConnected-1;
        if(extra<req)return -1;
        return req;
    }
};