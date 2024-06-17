class Solution {
public:
    bool judgeSquareSum(int c) {
        int rangemax=-1;
        for(int i=1;i<=c;i++){
            if(i<=c/i){
                rangemax=i;
            }
            else break;
        }
        if(c==0)return true;
        long long lo=0,hi=rangemax;
        cout<<hi<<endl;
        while(lo<=hi){
            if(lo*lo*1ll+hi*hi*1ll==c*1ll)return true;
            else if(lo*lo*1ll+hi*hi*1ll<c*1ll)lo++;
            else hi--;
        }
        return false;
    }
};