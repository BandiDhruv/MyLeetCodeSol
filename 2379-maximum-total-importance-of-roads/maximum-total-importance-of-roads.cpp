class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // vector<int> adj[n];
        vector<int> indegree(n),imp(n,0);
        for(auto it:roads){
            // adj[it[0]].push_back(it[1]);
            // adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({indegree[i],i});
        }
        int cnt=n;
        while(!pq.empty()){
            imp[pq.top().second]=cnt--;
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
        long long sum=0;
        for(auto it:roads){
            // cout<<it[0]<<" - "<<imp[it[0]]<<" | "<<it[1]<<" - "<<imp[it[1]]<<endl;
            sum+=imp[it[0]]*1ll+imp[it[1]]*1ll;
        }
        return sum;
    }
};