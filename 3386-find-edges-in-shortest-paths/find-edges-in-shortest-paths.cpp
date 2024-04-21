class Solution {
public:
    void dijk(int src,unordered_map<int,vector<pair<int,int>>>&mp,vector<int>&dist,int n){
        dist[src]=0;
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(!vis[node])
                vis[node]=true;
            else continue;
            for(auto it:mp[node]){
                int nnode=it.first;
                int ndis=it.second;
                if(!vis[nnode] && dist[node]+ndis<dist[nnode]){
                    dist[nnode]=dist[node]+ndis;
                    pq.push({dist[nnode],nnode});
                }
            }
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:edges){
            mp[it[0]].push_back({it[1],it[2]});
            mp[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dis1(n,1e9),dis2(n,1e9);
        dijk(0,mp,dis1,n);
        dijk(n-1,mp,dis2,n);
        vector<bool> ans(edges.size(),false);
        int c=0;
        for(auto it:edges){
            int u=it[0],v=it[1],w=it[2];
            if(dis1[u]+dis2[v]+w==dis1[n-1]){
                ans[c]=true;
                // ans[v]=true;
            }
            if(dis1[v]+dis2[u]+w==dis1[n-1]){
                // ans[u]=true;
                ans[c]=true;
            }
            c++;
        }
        return ans;
    }
};