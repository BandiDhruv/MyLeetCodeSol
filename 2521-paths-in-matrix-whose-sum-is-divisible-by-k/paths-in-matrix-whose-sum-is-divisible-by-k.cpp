class Solution {
public:
    int mod=1e9+7;
    int n,m;
    long long solve(vector<vector<int>>& grid, int k,int i,int j,int ans,vector<vector<vector<int>>> &t){
        if(i>=n || j>=m)return 0;
        if(t[i][j][ans]!=-1)
            return t[i][j][ans];
        if(i==n-1 && j==m-1){
            ans+=grid[i][j];
            ans%=k;
            return (ans==0);
        }
        int down=solve(grid,k,i+1,j,(ans+grid[i][j]%k)%k,t);
        int right=solve(grid,k,i,j+1,(ans+grid[i][j]%k)%k,t);
        return t[i][j][ans]=(down%mod + right%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(grid,k,0,0,0,dp)%mod;
    }
};