class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        queue<int> q;
        vector<int> adj[n];
        for(int i=0;i<p.size();i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
        }
        int cnt=0;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> vis(n,0);
        stack<int> st;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            st.push(x);
            vis[x]=1;
            for(auto it:adj[x])
            {
                if(!vis[it])
                {
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);
                }
            }
        }
        vector<int> ans;
        if(st.size()==n)
        {
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
        else
            return {};
    }
};