class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int n=ma.size(),m=ma[0].size(),col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ma[i][j]==0){
                    ma[i][0]=0;
                    if(j!=0)
                        ma[0][j]=0;
                    else col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(ma[i][j]!=0 ){
                    if(ma[i][0]== 0 || ma[0][j]==0)ma[i][j]=0;
                }
            }
        }
        if(ma[0][0]==0){
            for(int i=0;i<m;i++){
                ma[0][i]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                ma[i][0]=0;
            }
        }
        return ;
    }
};