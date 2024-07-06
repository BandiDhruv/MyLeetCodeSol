class Solution {
public:
    int n;
    void dfs(vector<int>&disFromRoot,vector<int>&parent,vector<int> adj[],int node,int dis,int par){
        disFromRoot[node]=dis;
        parent[node]=par;
        for(auto it:adj[node]){
            if(it!=par)
                dfs(disFromRoot,parent,adj,it,dis+1,node);
        }
        return;
    }
    int findMaxPathSum(int node,vector<int>adj[],vector<int>&amount,int par){
        int ansFromChild=-1e8;
        int currNode=amount[node];
        for(auto it:adj[node]){
            if(it!=par){
                ansFromChild=max(ansFromChild,findMaxPathSum(it,adj,amount,node));
            }
        }
        if(ansFromChild==-1e8)return currNode;
        return ansFromChild+currNode;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        n=amount.size();
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> disFromRoot(n,0),parent(n,0);
        dfs(disFromRoot,parent,adj,0,0,0);
        int bobdis=0;
        while(bob!=0){
            if(disFromRoot[bob]>bobdis)
                amount[bob]=0;
            else if(disFromRoot[bob]==bobdis)
                amount[bob]=amount[bob]/2;
            bob=parent[bob];
            bobdis++;
        }
        return findMaxPathSum(0,adj,amount,0);
    }
};