class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        
        vector<bool> prime(n+1,true);
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true)
            {
                cnt++;
                for(int j=2*i;j<n;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        
        return cnt;
    }
};