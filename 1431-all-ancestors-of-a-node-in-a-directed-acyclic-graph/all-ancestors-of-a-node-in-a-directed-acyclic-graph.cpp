class Solution {
public:
    void dfs(int node,int i,vector<vector<int>>&ans,vector<int>&vis,vector<int>adj[]){
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                ans[it].push_back(i);
                dfs(it,i,ans,vis,adj);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,ans,vis,adj);
        }
        return ans;
    }
};