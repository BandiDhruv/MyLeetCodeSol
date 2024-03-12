class Solution {
public:
    int n,m;
    bool isValid(int i,int j)
    {
        if( i<0 || j<0 || i>=n || j>=m )return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();m=grid[0].size();
        int cntfresh=0;
        vector<vector<int>> vis(n,vector<int>(m,0));    
        queue<pair<int,pair<int,int>>> q;//1,{x,y}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){q.push({0,{i,j}});vis[i][j]=2;}
                else vis[i][j]=0;
                if(grid[i][j]==1)cntfresh++;
            }
        }
        int ans=0,res=0;
        while(!q.empty())
        {
            int x=q.front().second.first;
            int y=q.front().second.second;
            int cnt=q.front().first;
            q.pop();
            ans=max(ans,cnt);
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny))
                {
                    if(vis[nx][ny]!=2 && grid[nx][ny] == 1)
                    {
                        vis[nx][ny]=2;
                        q.push({cnt+1,{nx,ny}});
                        res++;
                    }
                }
            }
        }
        if(res==cntfresh)
            return ans;
        return -1;
    }
};