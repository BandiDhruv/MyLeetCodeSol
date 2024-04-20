class Solution {
public:
    int n,m;
    typedef pair<int,int> P;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int nx,int ny){
        return nx<n && ny<m && nx>=0 && ny>=0;
    }
    int brx=-1,bry=-1;
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&land){
        brx=max(brx,i);
        bry=max(bry,j);
        vis[i][j]=true;
        for(auto it:dir){
            int nx=it[0]+i,ny=it[1]+j;
            if(isValid(nx,ny) && !vis[nx][ny] && land[nx][ny]==1)dfs(nx,ny,vis,land);
        }
        return;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(),m=land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(land[i][j]==1 && !vis[i][j])
                {
                    dfs(i,j,vis,land);
                    cout<<"hi";
                    ans.push_back({i,j,brx,bry});
                    brx=-1;
                    bry=-1;
                }
            }
        }
        return ans;
    }
};