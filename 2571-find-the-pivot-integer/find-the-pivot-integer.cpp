class Solution {
public:
    int pivotInteger(int n) {
        float sum=n*(n+1)/2.0;
        float ans=sqrt(sum);
        if(fmod(ans,1))
        return -1;
        return ans;
    }
};