class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        if ( l == r ) return l;
        if ( l <= 1 ) return 0;
        
        int b1 = 31 - __builtin_clz(l);
        int b2 = 31 - __builtin_clz(r);
        if ( b1 != b2 ) return 0;
        int ans = (1<<b1);
        // cout << ans;
        for(int i = b1; i >= 0 ; i--){
            int l_bit = 0;
            int r_bit = 0;
            if ( (l&(1<<i)) != 0 ) l_bit = 1;
            if ( (r&(1<<i)) != 0 ) r_bit = 1;
            cout << (1<<i) << endl;
            if ( l_bit == 1 && r_bit == 1 && (r-(1<<i) )<l){
                ans |= ( 1 << i);
            }
            
        }
        return ans;
    }
};