class Solution {
public:
    int n,m;
    bool isValid(int nr,int nc)
    {
        return (nr>=0 && nc>=0 && nr<n && nc<m);
    }
    void dfs(vector<vector<int>> &vis,int r,int c,vector<vector<char>> mat)
    {
        vis[r][c]=1;
        cout<<"aa   "<<endl;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(isValid(nr,nc) && mat[nr][nc]=='O' && vis[nr][nc]==0)
            {
                // vis[nr][nc]=1;
                dfs(vis,nr,nc,mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O')dfs(vis,i,0,mat);
            if(mat[i][m-1]=='O')dfs(vis,i,m-1,mat);
        }
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O')dfs(vis,0,i,mat);
            if(mat[n-1][i]=='O')dfs(vis,n-1,i,mat);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=1 &&  mat[i][j]=='O')mat[i][j]='X';
            }
        }
        
    }
};