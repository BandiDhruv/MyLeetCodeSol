class Solution {
public:
    int n;
    int dfs(vector<pair<int,int>> adj[],int node,int weight,int par,int k)
    {
        int ans=0;
        for(int i=0;i<adj[node].size();i++)
        {
            if(adj[node][i].first==par)
                continue;
            ans+=dfs(adj,adj[node][i].first,weight+adj[node][i].second,node,k);
        }
        if(weight%k==0)return ans+1;
        else return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int k) {
        n=edges.size()+1;
        vector<int> ans(n,0);
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<adj[i].size();j++)
            {
                temp.push_back(dfs(adj,adj[i][j].first,adj[i][j].second,i,k));
            }
            long long sum=0;
            for(auto it:temp)
                sum+=it;
            long long res=0;
            for(auto it:temp)
                res+=it*(sum-it);
            ans[i]=res/2;
        }
        return ans;
    }
};