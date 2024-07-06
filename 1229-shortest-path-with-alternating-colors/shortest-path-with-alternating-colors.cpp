class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> ans(n,vector<int>(3,1e8));
        vector<pair<int,int>> adj[n];
        for(auto it:redEdges)
            adj[it[0]].push_back({1,it[1]});
        for(auto it:blueEdges)
            adj[it[0]].push_back({0,it[1]});
        queue<pair<int,pair<int,int>>> q;
        for(auto it:adj[0]){
            q.push({0,{0,-1}});
        }
        ans[0]={0,0};
        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(auto it:adj[node]){
                if(col!=it.first && ans[it.second][it.first]>1+dis){
                    ans[it.second][it.first]=1+dis;
                    q.push({ans[it.second][it.first],{it.second,it.first}});
                }
            }
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int mini=min(ans[i][0],ans[i][1]);
            if(mini==1e8)res[i]=-1;
            else res[i]=mini;
        }
        return res;
    }
};