class Solution {
public:
    int n,m;
    bool isValid(int r,int c){
        return r<n && c<m && r>=0 && c>=0;
    }
    void dfs(bool &f,int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(!isValid(i,j))return;
        vis[i][j]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int ni=dx[k]+i;
            int nj=dy[k]+j;
            if(isValid(ni,nj) && !vis[ni][nj] && grid2[ni][nj]==1){
                if(grid1[ni][nj]==0)f=false;
                dfs(f,ni,nj,vis,grid1,grid2);
            }
        }
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n=grid1.size(),m=grid1[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    bool f=true;
                    dfs(f,i,j,vis,grid1,grid2);
                    if(f)ans++;
                }
            }   
        }    
        return ans;
    }
};