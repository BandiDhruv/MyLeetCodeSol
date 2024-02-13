class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        vector<unordered_set<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].insert(y);
            adj[y].insert(x);
        }
        queue<int> q;

        for(int i=0;i<adj.size();i++)
        {
            if(adj[i].size()==1)
            {
                q.push(i);
            }
        }
        while(n>2)
        {
            int len=q.size();
            n-=len;
            for(int i=0;i<len;i++)
            {
                int t=q.front();
                q.pop();
                for(auto &it:adj[t])
                {
                    adj[it].erase(t);
                    if(adj[it].size()==1)q.push(it);
                }
            }
        }
        vector<int> ans;
        // (q.begin(),q.end());
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};