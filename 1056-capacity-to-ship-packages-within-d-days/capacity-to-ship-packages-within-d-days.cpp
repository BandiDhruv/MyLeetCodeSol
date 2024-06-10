class Solution {
public:
    bool solve(int cap,vector<int>&w,int d){
        int sum=0;
        for(int i=0;i<w.size() ;i++){
            sum+=w[i];
            if(d<=0)return false;
            if(sum>cap){
                i--;
                sum=0;
                d--;
            }
        }
        return d>=0;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int ans=INT_MAX;
        int lo=0,hi=accumulate(w.begin(),w.end(),0);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(solve(mid,w,days)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};