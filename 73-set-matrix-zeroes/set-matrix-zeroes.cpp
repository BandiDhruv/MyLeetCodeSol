class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    int ni=i,nj=j;
                    while(ni>=0){
                        if(matrix[ni][j]!=0)
                            matrix[ni][j]=-1e9;
                        ni--;
                    }
                    ni=i;
                    while(ni<n){
                        if(matrix[ni][j]!=0)
                            matrix[ni][j]=-1e9;
                        ni++;
                    }
                    while(nj>=0){
                        if(matrix[i][nj]!=0)
                            matrix[i][nj]=-1e9;
                        nj--;
                    }
                    nj=j;
                    while(nj<m){
                        if(matrix[i][nj]!=0)
                            matrix[i][nj]=-1e9;
                        nj++;
                    }
                }
            }
        }
        for(auto &it:matrix){
            for(auto &i:it){
                if(i==-1e9)i=0;
            }
        }
    }
};