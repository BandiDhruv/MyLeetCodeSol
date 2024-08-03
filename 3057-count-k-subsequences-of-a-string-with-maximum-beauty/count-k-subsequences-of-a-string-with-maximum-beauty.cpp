#define ll unsigned long long
class Solution {
public:
unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat( long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
    // unordered_map<int,int> mp;
    // unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
    // int solve(string s,int k,int i,vector<int>&f,int b,set<char> st){
    //     if(k<0)
    //         return 0;
    //     if(k==0){
    //         mp[b]++;
    //         dp[i][k][b]=mp[b];
    //         return 0;
    //     }
    //     if(i>=s.size())
    //         return 0;
    //     if(dp.find(i)!=dp.end() && dp[i].find(k)!=dp[i].end() && dp[i][k].find(b)!=dp[i][k].end() )
    //         return dp[i][k][b];
    //     int nottake=solve(s,k,i+1,f,b,st);
    //     if(st.find(s[i])==st.end()){
    //         st.insert(s[i]);
    //         int take=solve(s,k-1,i+1,f,b+f[s[i]-'a'],st);
    //         st.erase(st.find(s[i]));
    //     }
    //     return nottake;
    // }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        // vector<int> f(26,0);
        // for(auto it:s)f[it-'a']++;
        // set<char> st;
        // int p=solve(s,k,0,f,0,st);
        // int maxi=INT_MIN;
        // cout<<mp.size()<<endl;
        // for(auto it:mp){
        //     maxi=max(maxi,it.first);
        // }        
        // if(maxi==INT_MIN)return 0;
        // return mp[maxi];
        ll ans=1;
        ll mod=1e9+7;
        vector<ll> f(26,0);
        unordered_set<char> st;
        for(auto it:s){
            f[it-'a']++;
            st.insert(it);
        }
        if(k>st.size())return 0;
        sort(f.rbegin(),f.rend());
        for(int i=0;i<k;i++){
            ans=ans*f[i];
            ans%=mod;
        }
        ll temp=f[k-1];
        ll cov=0,curr=0;
        for(int i=0;i<26;i++){
            if(curr==0){
                if(temp==f[i]){
                    curr++;cov=i;
                }
            }
            else{
                if(temp==f[i]){
                    curr++;
                }
                else break;
            }
        }
        return (ans*nCrModPFermat(curr,k-cov,mod))%mod;
    }
};