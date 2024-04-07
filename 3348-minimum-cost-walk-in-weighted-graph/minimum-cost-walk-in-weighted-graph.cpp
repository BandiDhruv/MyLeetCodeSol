class DisjointSet{
    vector<int> parent,rank,size,an;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        an.resize(n,(1<<30)-1);
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
    void andSum(int node,int val){
        int par=findUpar(node);
        an[par]&=val;
    }
    int getAndSum(int n){
        return an[n];
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
            an[pv]&=an[pu];
        }
        else 
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
            an[pu]&=an[pv];
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int q=query.size();
        vector<int> ans(q);
        DisjointSet ds(n);
        for(auto it:edges){
            ds.unionBySize(it[0],it[1]);
            ds.andSum(it[0],it[2]);
        }

        for(int i=0;i<q;i++){
            int s=query[i][0];
            int e=query[i][1];
            if(s==e)ans[i]=0;
            else if(ds.findUpar(s)==ds.findUpar(e))ans[i]=ds.getAndSum(ds.findUpar(s));
            else ans[i]=-1;

        }
        return ans;
    }
};