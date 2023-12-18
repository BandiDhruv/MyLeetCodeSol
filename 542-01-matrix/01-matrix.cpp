class Solution {
public:
    bool isValid(int r,int c,int n,int m)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                }
                
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>> ans(n,vector<int>(m,0));
        // for(auto it:q)
        // {
            // vis[it.first.first][it.first.second]=1;
        // }
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            ans[x][y]=t;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny,n,m))
                {
                    if(mat[nx][ny]!=0 && vis[nx][ny]==0)
                    {
                        q.push({{nx,ny},t+1});
                        vis[nx][ny]=1;
                    }
                    // else q.push({{nx,ny},t+1});
                }
            }
        }
        return ans;
    }
};