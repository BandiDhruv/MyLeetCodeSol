class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]==-1)continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> temp(n,-1);
        queue<pair<int,int>> q;
        q.push({node1,0});
        vector<int> vis1(n,0);
        while(!q.empty()){
            int node=q.front().first,cnt=q.front().second;
            vis1[node]=1;
            temp[node]=max(temp[node],cnt);
            q.pop();
            for(auto it:adj[node]){
                if(!vis1[it])
                    q.push({it,cnt+1});
            }
        }
      vector<int>vis2(n,0);
        q.push({node2,0});
        while(!q.empty()){
            int node=q.front().first,cnt=q.front().second;
            vis2[node]=1;
            temp[node]=max(temp[node],cnt);
            q.pop();
            for(auto it:adj[node]){
                if(!vis2[it])
                    q.push({it,cnt+1});
            }
        }
        int ans=INT_MAX;
        int res=1e8;
        for(int i=0;i<n;i++){
            // cout<<temp[i]<<" "<<ans<<" "<<i<<endl;
            if(vis1[i] && vis2[i]){
                if(temp[i]<ans){
                    ans=temp[i];
                    res=i;
                }
                else if(temp[i]==ans)
                    res=min(i,res);
            }
        }
        return res==1e8?-1:res;
    }
};