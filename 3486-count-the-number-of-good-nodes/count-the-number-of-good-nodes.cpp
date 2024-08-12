class Solution {
public:
    vector<int> sizes;
    int n,ans=0;
    int dfs(vector<int>adj[],int node,int parent){
        int ans=0;
        for(auto it:adj[node]){
            if(it!=parent){
                ans+=dfs(adj,it,node);
            }
        }
        sizes[node]=1+ans;
       return sizes[node];
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        n=edges.size()+1;
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        sizes.resize(n,0);
        int p=dfs(adj,0,-1);
        for(int i = 0; i < n; i++){
            bool flag = true;
            int prev = -1;
            for(auto nbr : adj[i]) {
                if(sizes[nbr] < sizes[i]){
                    if(prev == -1) prev = sizes[nbr];
                    else if(prev != sizes[nbr]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};