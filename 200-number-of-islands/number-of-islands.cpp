class Solution {
public:
    bool isValid(int x,int y,int n,int m){
        return x<n && y<m && x>=0 && y>=0;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    q.push({i,j});
                    ans++;
                }
                while(!q.empty()){
                    int x=q.front().first,y=q.front().second;
                    q.pop();
                    if(!vis[x][y])
                        vis[x][y]=true;
                    else continue;
                    for(auto it:dir){
                        int nx=x+it.first,ny=it.second+y;
                        if(isValid(nx,ny,grid.size(),grid[0].size()) && !vis[nx][ny]  && grid[nx][ny]=='1')q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};