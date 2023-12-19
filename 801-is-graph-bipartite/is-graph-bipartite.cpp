class Solution {
public:
    bool solve(int start,vector<int>&color,vector<vector<int>>&graph)
    {
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto it:graph[x])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[x];
                    q.push(it);
                }
                else if(color[it]==color[x])return false;
            }
        }
        return true;
    }
    bool solvedfs(int node,int col,vector<int>&color,vector<vector<int>>&graph)
    {
        color[node]=col;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                if(solvedfs(it,!col,color,graph)==false)return false;
            }
            else if(color[it]==col)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size());
        for(int i=0;i<graph.size();i++)
            color[i]=-1;
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            // if(solve(i,color,graph)==false)return false;
            if(solvedfs(i,0,color,graph)==false)return false;
        }      
        return true;
    }
};