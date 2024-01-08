class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>&vis,vector<int> adj[],vector<int>& tin, vector<int>&low,vector<vector<int>> &ans)
    {
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)continue;
            if(vis[it]==0)
            {
                dfs(it,node,vis,adj,tin,low,ans);
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node])
                {
                    ans.push_back({node,it});
                }
            }
            else {
                low[node]=min(low[it],low[node]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> tin(n,0),low(n,0);
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            dfs(i,-1,vis,adj,tin,low,ans);
        }
        return ans;
    }
};