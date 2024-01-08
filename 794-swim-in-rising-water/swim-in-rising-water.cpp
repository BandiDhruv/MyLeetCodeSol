class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    bool isValid(int r,int c,int n)
    {
        return (r>=0 && c>=0 && r<n && c<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        //{maximum uptillnow,{i,j}}
        priority_queue<P,vector<P>,greater<P>> pq;
        // unordered_set<P> pq;
        pq.push({grid[0][0],{0,0}});
        // int ans=INT_MAX;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty())
        {
            int mw=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            // vis[r][c]=1;
            if(r==n-1 && c==n-1) return mw;
            for(int i=0;i<4;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                if(isValid(nr,nc,n) && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    int temp=max(mw,grid[nr][nc]);
                    pq.push({temp,{nr,nc}});
                }
            }
        }
        return -1;
    }
};