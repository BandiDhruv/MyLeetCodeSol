class Solution {
public:
    bool isValid(int x,int y,int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int cntfresh=0; 
        int vis[grid.size()][grid[0].size()];
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }

                else{
                    vis[i][j]=0;
                }

                if(grid[i][j]==1)cntfresh++;
            }
        }
        int xd[]={-1,0,1,0};
        int yd[]={0,1,0,-1};
        int time=0;
        int cnt=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            q.pop(); 
            time=max(time,t);
            for(int j=0;j<4;j++)
            {
                int nx=x+xd[j];
                int ny=y+yd[j];
                if(isValid(nx,ny,grid.size(),grid[0].size()))
                {
                    if(vis[nx][ny]!=2 && grid[nx][ny]==1)
                    {
                        q.push({{nx,ny},t+1});
                        vis[nx][ny]=2;
                        cnt++;
                    }
                }
            }
        }
        if(cnt==cntfresh)
            return time;
        else return -1;
    }
};