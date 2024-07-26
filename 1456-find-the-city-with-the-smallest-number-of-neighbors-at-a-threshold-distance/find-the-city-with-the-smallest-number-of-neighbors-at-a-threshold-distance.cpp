class Solution {
public:
    typedef pair<int, int> P;

    void dijk(int src, vector<vector<int>>& dist, vector<pair<int, int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> vis(dist.size(), 0);
        pq.push({0, src});
        dist[src][src] = 0;
        
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;

            for (auto it : adj[node]) {
                if (!vis[it.first] && dis + it.second < dist[src][it.first]) {
                    dist[src][it.first] = dis + it.second;
                    pq.push({dist[src][it.first], it.first});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        vector<pair<int, int>> adj[n];

        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for (int i = 0; i < n; ++i) {
            dijk(i, dist, adj);
        }

        int ans = INT_MAX, res = -1;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= k) cnt++;
            }
            if (cnt <= ans) {
                ans = cnt;
                res = i;
            }
        }
        return res;
    }
};
