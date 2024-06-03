class NumMatrix {
public:
    vector<vector<int>> pre;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size(),m=matrix[0].size();
        pre.resize(matrix.size(),vector<int>(matrix[0].size(),0));
        pre[0][0]=matrix[0][0];
        for(int i=1;i<m;i++){
            pre[0][i]=matrix[0][i]+pre[0][i-1];
        }
        for(int i=1;i<n;i++){
            pre[i][0]=matrix[i][0]+pre[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]+matrix[i][j]-pre[i-1][j-1];
            }
        }
        for(auto it:pre){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1>0 && col1>0)
            return pre[row2][col2]-pre[row1-1][col2]-pre[row2][col1-1]+pre[row1-1][col1-1];
        if(row1>0) 
            return pre[row2][col2]-pre[row1-1][col2];
        if(col1>0)
            return pre[row2][col2]-pre[row2][col1-1];
        return pre[row2][col2];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */