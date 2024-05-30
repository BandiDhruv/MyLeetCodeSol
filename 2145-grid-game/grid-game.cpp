class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long ans=1e18;
        vector<long long> pre1(n),pre2(n);
        // grid[0][0]=0;
        pre1[0]=grid[0][0];
        pre2[0]=grid[1][0];

        for(int i=1;i<n;i++)pre1[i]=pre1[i-1]+1ll*grid[0][i];
        for(int i=1;i<n;i++)pre2[i]=pre2[i-1]+1ll*grid[1][i];
        for(int i=0;i<n;i++){
            long long a=pre1[n-1]-pre1[i];
            long long b=i==0?0:pre2[i-1];
            ans=min(ans,max(a,b));
        }
        return ans;
    }
};