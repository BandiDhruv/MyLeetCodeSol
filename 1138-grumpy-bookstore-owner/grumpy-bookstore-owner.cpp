class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int temp=0;
        for(int i=0;i<c.size();i++){
            temp+=(g[i]==0)?c[i]:0;
        }
        int l=0;
        int ans=0;
        for(int r=0;r<c.size();r++){
            if(g[r]==1)temp+=c[r];
            while(r-l+1>m && l<r){
                if(g[l]==1)temp-=c[l];
                l++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};