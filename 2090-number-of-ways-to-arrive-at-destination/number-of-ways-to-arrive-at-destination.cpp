class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long ,long long >> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long ,long long >,vector<pair<long long ,long long >>,greater<pair<long long ,long long >>> pq;
        pq.push({0,0});
        vector<long long>dis(n,1e18),ways(n,0);
        dis[0]=0;
        ways[0]=1;
        long long mode=1e9+7;
        while(!pq.empty())
        {
            long long dist=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                long long adjnode=it.first;
                long long adjdis=it.second;
                if(dist+adjdis<dis[adjnode])
                {
                    dis[adjnode]=dist+adjdis;
                    pq.push({dis[adjnode],adjnode});

                    ways[adjnode]=ways[node];
                }
                else if(dist+adjdis==dis[adjnode])
                    ways[adjnode]=(ways[adjnode]+ways[node])%mode;
            }
        }
        return ways[n-1]%mode;
    }
};