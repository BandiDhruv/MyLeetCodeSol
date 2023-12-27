class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int n,m;
    bool isValid(int x,int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        eff[0][0]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty())
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int effort=pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny))
                {
                    int curef=max(abs(heights[nx][ny]-heights[x][y]),effort);
                    if(curef<eff[nx][ny]){
                        eff[nx][ny]=curef;
                        pq.push({curef,{nx,ny}});
                    }
                }
            }
        }
        if( eff[n-1][m-1]==1e9) return 0;
        return eff[n-1][m-1];

    }
};