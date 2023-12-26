class Solution {
public:
    int n,m;
    bool isValid(int x,int y)
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
struct cmp{
    bool operator()(const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2) const {
        return p1.first > p2.first;
    }
};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        int ans=-1;
        // vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        if(grid[0][0]==1)return -1;
        if(n==1 && m==1) return 1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> pq;
        pq.push({1,{0,0}});
        vector<pair<int,int>>dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        vector<vector<int>> res(n,vector<int>(m,1e9));
        res[0][0]=0;

        while(!pq.empty())
        {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int dis=pq.top().first;
            // vis[x][y]=1;
            // cout<<x<<" "<<y<<" "<<endl;
            pq.pop();
            // if(x==n-1 && y==m-1){
                // ans=dis;break;
            // }
            for(auto it:dir)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(isValid(nx,ny))
                {
                    if(grid[nx][ny]==0 && dis+1<res[nx][ny])
                    {
                        res[nx][ny]=1+dis;
                        pq.push({dis+1,{nx,ny}});
                    }
                }
            }
        }
        // if(ans==0)
        return (res[n-1][m-1]==1e9)?-1:res[n-1][m-1];

    }
};

