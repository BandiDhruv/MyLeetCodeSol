class Solution {
public:
    int result=-1;
    void dfs(int node,vector<int>&vis,
    vector<int>& edges,vector<int>& count,
    vector<int>& dfsvis)
    {
        if(node!=-1)
        {
            vis[node]=1;
            dfsvis[node]=1;
            int adjnode=edges[node];
            if(adjnode!=-1 && !vis[adjnode])
            {
                count[adjnode]=count[node]+1;
                dfs(adjnode,vis,edges,count,dfsvis);
            }
            else{
                if(adjnode!=-1 && dfsvis[adjnode])
                {
                    result = max(result,count[node]-count[adjnode]+1);
                }
            }
            dfsvis[node]=0;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> vis(n,0),count(n,1);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,edges,count,dfsvis);
            }
        }
        return result;

    }
};