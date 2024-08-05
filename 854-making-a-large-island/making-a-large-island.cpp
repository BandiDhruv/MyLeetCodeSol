class DisjointSet{
public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(parent[node]==node)
            return parent[node];
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv)return;
        if(size[pu]>size[pv]){
            size[pu]+=size[pv];
            parent[pv]=parent[pu];
        }else{
            size[pv]+=size[pu];
            parent[pu]=parent[pv];
        }
        return;
    }
    int getSize(int node){
        return size[findUpar(node)];
    }
};
class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int ans=INT_MIN;
        n=grid.size();
        m=grid[0].size();
        unordered_map<int,unordered_map<int,int>> mp;
        DisjointSet ds(n*m+1);
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i][j]=c++;
            }
        }
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nr=dx[k]+row;
                            int nc=dy[k]+col;
                            if(isValid(nr,nc) && !vis[nr][nc] && grid[nr][nc]==1){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                                ds.unionBySize(mp[nr][nc],mp[row][col]);
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    set<int> temp;
                    int cnt=0;
                    for(int k=0;k<4;k++){
                        int nr=i+dx[k],nc=j+dy[k];
                        if(isValid(nr,nc) && grid[nr][nc]==1)
                        {
                            temp.insert(ds.findUpar(mp[nr][nc]));
                        }
                    }
                    for(auto it:temp)cnt+=ds.getSize(it);
                    ans=max(ans,cnt+1);
                }   
            }
        }
        if(ans==INT_MIN )
            return (grid[0][0]==1)?n*m:1;
        return ans;
    }
};