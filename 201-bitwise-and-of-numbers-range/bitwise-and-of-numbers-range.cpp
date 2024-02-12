class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        if(l==r)return r;
        if(l<=1)return 0;
        int ans=l&r;
        if((int)log2(l)!=(int)log2(r))
            return 0;
        for(int i=l+1;i<r;i++)
        {
            ans&=i;
        }
        return ans;
    }
};