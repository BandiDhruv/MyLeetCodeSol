class Solution {
public:
    int minBitFlips(int s, int g) {
        int cnt=0;
        for(int i=31;i>=0;i--)
        {
            int sbit=(s>>i)&1;
            int gbit=(g>>i)&1;
            cnt+=(sbit!=gbit);
        }
        return cnt;
    }
};