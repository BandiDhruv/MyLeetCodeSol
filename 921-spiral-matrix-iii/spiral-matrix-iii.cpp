class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rs, int cs) {
        n=rows,m=cols;
        vector<pair<int,int>> d={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans;
        int dir=0;
        int steps=1;
        while(ans.size()<n*m){
            cout<<ans.size()<<" ";
            for(int k=0;k<2;k++){
                for(int i=0;i<steps;i++){
                    if(isValid(rs,cs))
                        ans.push_back({rs,cs});
                    rs+=d[dir].first;
                    cs+=d[dir].second;
                }
                dir=(dir+1)%4;
            }
            steps++;
        }
        return ans;
    }
};