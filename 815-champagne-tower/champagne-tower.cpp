class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<double> ans(1,1.0*poured);
        for(int i=1;i<=qr;i++){
            vector<double>temp(i+1,0.0);
            for(int j=0;j<i;j++){
                double extra=ans[j]-1.0;
                if(extra>0.0){
                    temp[j]+=extra*(0.5);
                    temp[j+1]+=extra*(0.5);
                }
            }
            ans=temp;
        }
        return min(1.0,ans[qg]);
    }
};