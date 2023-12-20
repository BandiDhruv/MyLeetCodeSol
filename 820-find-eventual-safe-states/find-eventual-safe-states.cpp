class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        vector<int> indegree(graph.size());
        vector<int> adjrev[graph.size()];
        vector<int>ans;
        for(int i=0;i<graph.size();i++)
        {
            // i->it
            // it->i

            for(auto it:graph[i])
            {
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }   
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            vis[x]=1;
            ans.push_back(x);
            for(auto it:adjrev[x])
            {
                if(!vis[it])
                {
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};