class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>>pq;
        vector<pair<int,double>> adj[1+n];
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0],y=edges[i][1];
            adj[x].push_back({y,succProb[i]});
            adj[y].push_back({x,succProb[i]});
        }
        vector<double> dis(n,INT_MIN);
        pq.push({1.0,start_node});
        dis[start_node]=1.0;
        while(!pq.empty()){
            auto p=pq.top().first;
            auto node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(p*it.second>dis[it.first]){
                    dis[it.first]=p*it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        return dis[end_node]==INT_MIN?0:dis[end_node];
    }
};