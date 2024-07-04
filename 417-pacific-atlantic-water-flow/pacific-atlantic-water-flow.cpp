class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    void bfs(queue<pair<int,int>> &q,vector<vector<bool>>& vis,vector<vector<int>>&heights){
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
            for(int k=0;k<4;k++){
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(isValid(nx,ny) && !vis[nx][ny] && heights[nx][ny]>=heights[x][y]){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        vector<vector<bool>> a(n,vector<bool>(m,false)),p(n,vector<bool>(m,false));
        queue<pair<int,int>> qa,qp;
        for(int i=0;i<m;i++){
            p[0][i]=true;
            qp.push({0,i});
            a[n-1][i]=true;
            qa.push({n-1,i});
        }
        for(int i=0;i<n;i++){
            p[i][0]=true;
            qp.push({i,0});
            a[i][m-1]=true;
            qa.push({i,m-1});
        }
        bfs(qa,a,heights);
        bfs(qp,p,heights);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && p[i][j])ans.push_back({i,j});
            }
        }
        return ans;

    }
};