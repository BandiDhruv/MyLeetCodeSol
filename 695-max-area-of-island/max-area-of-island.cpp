class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n,m;
    bool isValid(int i,int j){
        return (i>=0 && i<n && j<m && j>=0);
    }
    void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis,int &sum)
    {
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(isValid(nx,ny) && !vis[nx][ny] && grid[nx][ny]==1){
                sum++;
                dfs(grid,nx,ny,vis,sum);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int sum=1;
                    dfs(grid,i,j,vis,sum);
                    ans=max(ans,sum);
                }
            }   
        }    
        return ans;
    }
};