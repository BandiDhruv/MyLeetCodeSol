class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dis(n+1,1e9);
        priority_queue<pair<int,int>> pq;
        // [dis,node]
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjtime=it.second;
                int adjnode=it.first;
                if(adjtime+time<dis[adjnode])
                {
                    dis[adjnode]=adjtime+time;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dis[i]);
        }
        if(ans==1e9)
        return -1;
        else return ans;
    }
};