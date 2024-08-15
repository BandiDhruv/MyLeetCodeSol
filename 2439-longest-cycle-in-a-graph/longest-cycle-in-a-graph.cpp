class Solution {
public:
    int res = -1;
    void dfs(int node, vector<int>& edges, vector<bool> &visited, vector<int>& dist, vector<bool> &pathvis){
        if(node != -1) {
            visited[node] = true;
            pathvis[node] = true;
            int adjnode= edges[node];
            if(adjnode!=-1 && !visited[adjnode]) {
                dist[adjnode] = dist[node] + 1;
                dfs(adjnode, edges, visited, dist, pathvis);
            } else if(adjnode!=-1 && pathvis[adjnode] == true) { 
                res=max(res,dist[node]-dist[adjnode]+1);
            }
            pathvis[node] = false;
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> dist(n, 1);
        vector<bool> pathvis(n, false);
        for(int i = 0 ; i<n; i++) {
            if(!visited[i]) {
                dfs(i, edges, visited, dist, pathvis);
            }   
        }
        return res;
    }
};