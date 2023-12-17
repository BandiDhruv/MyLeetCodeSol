class Solution {
public:
    bool isValid(int r,int c,int n,int m)
    {
        return (r>=0 && c>=0 && r<n && c<m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        int n=image.size(),m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // for(int i=0;i<image.size();i++)
        // {
        //     for(int j=0;j<image[0].size();j++)
        //     {

        //     }
        // }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            image[r][c]=color;
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(isValid(nr,nc,n,m))
                {
                    if(image[nr][nc]==originalColor && vis[nr][nc]!=1)
                    {
                        image[nr][nc]=color;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return image;
    }
};