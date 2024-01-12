class Solution {
public:
class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUpar(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)return ;
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }    
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        int a=-1,b=-1;
        int bl1=-1,bl2=-1;
        vector<int> indegree(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(indegree[edges[i][1]]!=-1)
            {
                bl1=i;
                bl2=indegree[edges[i][1]];
                break;
            }
            indegree[edges[i][1]]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(i==bl1)continue;
            int u=edges[i][0];
            int v=edges[i][1];
            int pu=ds.findUpar(u);
            int pv=ds.findUpar(v);
            if(pu==pv){
                if(bl1==-1){
                    return edges[i];
                }else{
                    return edges[bl2];
                }
            }
            ds.unionBySize(u,v);
        }
        return edges[bl1];
        // if(a==-1 && b==-1) return{edges[bl1][0],edges[bl1][1]};

        // return {edges[bl2][0],edges[bl2][1]};
    }
};