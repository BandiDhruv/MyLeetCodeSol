class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> dir={{1,0},{-1,-1},{-1,1},{1,-1},{1,1},{0,1},{0,-1},{-1,0}};
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                int r1sum=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1];
                int r2sum=grid[i][j-1]+grid[i][j]+grid[i][j+1];
                int r3sum=grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                int c1sum=grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1];
                int c2sum=grid[i-1][j]+grid[i][j]+grid[i+1][j];
                int c3sum=grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1];
                int d1sum=grid[i][j]+grid[i-1][j-1]+grid[i+1][j+1];
                int d2sum=grid[i][j]+grid[i-1][j+1]+grid[i+1][j-1];
                if(r1sum==r2sum && r2sum==r3sum && r3sum==c1sum && c1sum==c2sum && c2sum==c3sum && c3sum==d1sum && d1sum==d2sum){
                    if(grid[i][j]<=9){
                        bool f=true;
                        unordered_set<int> st;
                        st.insert(grid[i][j]);
                        for(auto it:dir){
                            
                            if(grid[i+it[0]][j+it[1]]>9 || grid[i+it[0]][j+it[1]]<1 )f=false;
                            st.insert(grid[i+it[0]][j+it[1]]);
                        }
                        if(f && st.size()==9)ans++;
                    }
                }
            }
        } 
        return ans;   
    }
};