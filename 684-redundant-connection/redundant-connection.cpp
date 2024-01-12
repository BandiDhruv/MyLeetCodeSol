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
class Solution {
public:
// vector<pair<int,int>> ans;

    // void dfs(int node,vector<int>&vis,vector<int> adj[],int parent)
    // {
    //     vis[node]=1;
    //     for(auto it:adj[node])
    //     {
    //         if(!vis[it])
    //         {
    //             dfs(it,vis,adj,node);
    //         }
    //         if(it!=parent)ans.push_back({node,it}); ;
    //         // else{
    //             // ans.push_back({node,it});
    //         // }
    //     }
    // }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(n);
        vector<pair<int,int>> ans;
        // vector<int> vis(n+1,0);
        // vector<int> adj[n+1];
        for(int i=0;i<n;i++)
        {
            // adj[edges[i][0]].push_back(edges[i][1]);
            // adj[edges[i][1]].push_back(edges[i][0]);
            int x=edges[i][0];
            int y=edges[i][1];
            int px=ds.findUpar(x);
            int py=ds.findUpar(y);
            if(px==py)
            {
                ans.push_back({x,y});
            }
            // else{
                ds.unionBySize(x,y);
            // }
        }
        // for(int i=1;i<=n;i++)
        // {
        //     if(!vis[i])
        //     {
        //         dfs(i,vis,adj,-1);
        //     }
        // }
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].first<<"  "<< ans[i].second<<endl;
        }
        return {ans[0].first,ans[0].second};
    }
};