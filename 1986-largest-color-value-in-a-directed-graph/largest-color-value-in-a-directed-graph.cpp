class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<int> adj[colors.size()+1];
        vector<int>indegree(colors.size()+1,0);
        for(auto it:edges){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int> q;
        for(int i=0;i<colors.size();i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<vector<int>> dp(colors.size()+1,vector<int>(26,0));
        for(int i=0;i<colors.size();i++)
            dp[i][colors[i]-'a']++;
        int ans=INT_MIN;
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto &it:adj[node]){
                for(int i=0;i<26;i++)
                    dp[it][i]=max(dp[it][i],dp[node][i]+((colors[it]-'a'==i)?1:0));
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            for(int i=0;i<26;i++){
                ans=max(ans,dp[node][i]);
            }
        }

        if(cnt<colors.size())
            return -1;
        return ans;
    }
};