class Solution {
public:
    int dfs(vector<int>adj[],int node,int par,int seats,long long &ans){
        int p=1;
        for(auto it:adj[node]){
            if(it==par)continue;
            p+=dfs(adj,it,node,seats,ans);
        }
        if(node>0)
            ans+=(p+seats-1)/seats;
        return p;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans=0;
        // 3 1 2 
        // 2 2 2
        vector<int> adj[roads.size()+1];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(adj,0,-1,seats,ans);
        return ans;
    }
};