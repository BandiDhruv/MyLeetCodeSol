class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return __builtin_popcount(n);
        int c=0;
        while(n!=0)
        {
            c+=n&1;
            n=n>>1;
                    }
        return c;
    }
};