class Solution {
public:
    void dfs(int idx,vector<vector<int>>& adj,vector<bool> &vis)
    {
        for(int i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==1 && !vis[i])
            {
                vis[i]=true;
                dfs(i,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        vector<bool> vis(adj.size()+1,false);
        int c=0;
        for(int i=0;i<adj.size();i++)
        {
            if(!vis[i])
            {
                vis[i]=true;
                dfs(i,adj,vis);
                c++;
            }
        }
        return c;
    }
};