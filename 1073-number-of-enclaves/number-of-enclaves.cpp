class Solution {
public:
    int n,m;
    bool isValid(int r,int c)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
    void dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid)
    {
        vis[r][c]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(isValid(nr,nc) && grid[nr][nc]==1 && vis[nr][nc]==0)dfs(nr,nc,vis,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0,vis,grid);
            }
            if(grid[i][m-1]==1)
            {
                dfs(i,m-1,vis,grid);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                dfs(0,j,vis,grid);
            }
            if(grid[n-1][j]==1)
            {
                dfs(n-1,j,vis,grid);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};