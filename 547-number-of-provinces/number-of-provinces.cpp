class Solution {
public:
    void dfs(vector<vector<int>>& a,int node,vector<bool> &vis)
    {
        vis[node]=true;
        for(int i=0;i<a[node].size();i++)
        {
            if(a[node][i]==1 && !vis[i])
                dfs(a,i,vis);
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> vis(isConnected.size());
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i])
            {
                dfs(isConnected,i,vis);
                ans++;
            }
        }
        return ans;
    }
};