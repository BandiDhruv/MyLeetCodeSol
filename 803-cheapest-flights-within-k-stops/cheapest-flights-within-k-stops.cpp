class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<P> q;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,1e9);
        dis[src]=0;
        q.push({0,{src,0}});
        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dist=q.front().second.second;
            q.pop();
            if(stops>k && node!=dst) break;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjdist=it.second;
                if(adjdist+dist<dis[adjnode])
                {
                    dis[adjnode]=adjdist+dist;
                    q.push({stops+1,{adjnode,dis[adjnode]}});
                }
            }
        }
        return (dis[dst]==1e9)?-1:dis[dst];
        
    }
};