class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return (i>=0 && j>=0 && i<n && j<m);
    }

    void dfs(bool &f,vector<vector<int>> &vis,int i,int j,vector<vector<int>> &grid){
        vis[i][j]=1;
        // cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nx=dx[k]+i,ny=dy[k]+j;
            if(isValid(nx,ny) && !vis[nx][ny]){
                if(grid[nx][ny]==2)
                    f=false;
                if(grid[nx][ny]==0)
                    dfs(f,vis,nx,ny,grid);
            }
        }
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)grid[i][0]=2;
            if(grid[i][m-1]==0)grid[i][m-1]=2;
        }    
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)grid[0][i]=2;
            if(grid[n-1][i]==0)grid[n-1][i]=2;
        }
        for(auto it:grid){
            for(auto i:it)cout<<i<<" ";
            cout<<endl;
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool f=true;
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(f,vis,i,j,grid);
                    if(!f)continue;
                    else cnt++;
                }
            }
        }
        return cnt;
    }
};