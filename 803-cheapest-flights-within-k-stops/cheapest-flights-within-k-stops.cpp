class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            int x=it[0];
            int y=it[1];
            int p=it[2];
            adj[x].push_back({y,p});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});//{stops,{node,cost}}
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k && node!=dst) break;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjcost=it.second;
                if(cost+adjcost<dist[adjnode])
                {
                    dist[adjnode]=cost+adjcost;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst]==1e9) 
            return -1;
        return dist[dst];
    }
};