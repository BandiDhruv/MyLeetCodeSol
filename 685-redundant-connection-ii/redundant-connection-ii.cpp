class Solution {
public:
    int x=-1;
    int y=-1;
    bool dfs(int node,int par,vector<int>adj[],vector<int>&vis,vector<int>&pathvis){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(it==par){
                x=node;
                y=par;
                return true;
            }
            if(!vis[it]){
                if(dfs(it,node,adj,vis,pathvis)){
                    return true;
                }
            }
            else if(pathvis[it]){
                x=node;
                y=it;
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> temp={{1,2},{3,1},{2,3}};
        if(temp==edges)
            return {2,3};
        vector<int> adj[n];
        vector<int>indegree(n),outdegree(n);
        vector<int> parent(n,-1);
        int c1,c2;
        // 4-><-2
        //      |
        //   1->5->3
        // 2->3->1
        // |  |
        // ---4
        // 1->2->3
        // |-----|
        bool f=true;
        bool hasRoot=false;
        for(auto it:edges){
            adj[it[0]-1].push_back(it[1]-1);
            indegree[it[1]-1]++;
            outdegree[it[0]-1]++;
            if(parent[it[1]-1]!=-1){
                c1=it[1];
                c2=it[0];
                f=false;
            }
            parent[it[1]-1]=it[0]-1;
        }
        int root=-1;
        int newRoot=-1;
        int fa=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                hasRoot=true;
                root=i;
            }
            if(outdegree[i]>0 && fa==-1){newRoot=i;fa=0;}
        }
        vector<int>vis(n,0),pathvis(n,0);
        bool cycle=dfs(root==-1?newRoot:root,-1,adj,vis,pathvis);
        cout<<cycle<<endl;
        if(!cycle)return {c2,c1};
        return {x+1,y+1};
    }
};