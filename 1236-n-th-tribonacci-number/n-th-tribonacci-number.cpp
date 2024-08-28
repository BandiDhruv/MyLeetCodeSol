class Solution {
public:
    map<int,int> mp;
    int tribonacci(int n) {
        // memset(t,-1,sizeof(t));
        if(n==0)return n;
        if(n<=2)return 1;
        if(mp.find(n)!=mp.end())
            return mp[n];
        return mp[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};