class Solution {
public:
    int t,c;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        t=time;
        c=change;
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        queue<pair<int,int>/*,vector<pair<int,int>>,greater<pair<int,int>>*/> pq;
        vector<int> dis(n,1e8),sdis(n,1e8);
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            int cost=pq.front().first;
            int node=pq.front().second;
            pq.pop();
            // if(sdis[n-1]!=1e8)break;
            for(auto it:adj[node]){
                // cout<<it+1<<" "<<node+1<<" "<<cost<<endl;
                int nnode=it;
                if(sdis[nnode]!=1e8)continue;
                if(cost+time+((cost/change)%2==0?0:change*((cost/change)+1)-cost)<dis[nnode] ){
                    sdis[nnode]=dis[nnode];
                    dis[nnode]=cost+time+((cost/change)%2==0?0:change*((cost/change)+1)-cost);
                    pq.push({dis[nnode],nnode});
                }else if(cost+time+((cost/change)%2==0?0:change*((cost/change)+1)-cost)<sdis[nnode] && cost+time+((cost/change)%2==0?0:change*((cost/change)+1)-cost)!=dis[nnode]){
                    sdis[nnode]=cost+time+((cost/change)%2==0?0:change*((cost/change)+1)-cost);
                    pq.push({sdis[nnode],nnode});
                }
            }
        }
        cout<<sdis[n-1]<<" "<<dis[n-1];
        return sdis[n-1];
    }
};