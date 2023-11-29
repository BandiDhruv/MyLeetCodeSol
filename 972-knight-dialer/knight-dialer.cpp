class Solution {
public:
    int mr=4,mc=3;
    int mod=1e9+7;
    vector<vector<int>> mat;
    int solvemem(int n,int idx,int col,int row,vector<vector<vector<int>>> &dp){
        if(idx==n){
            if(row>=mr || col>=mc || row<0 || col<0)
                return 0;
            else if(mat[row][col]<0)
                return 0;
            return 1;
        }
        if(dp[idx][row][col]!=-1)
            return dp[idx][row][col];
        return dp[idx][row][col]=(solvemem(n,idx+1,col+2,row+1,dp)+solvemem(n,idx+1,col+2,row-1,dp)+solvemem(n,idx+1,col-2,row+1,dp)+solvemem(n,idx+1,col-2,row-1,dp)+solvemem(n,idx+1,col+1,row+2,dp)+solvemem(n,idx+1,col+1,row-2,dp)+solvemem(n,idx+1,col-1,row+2,dp)+solvemem(n,idx+1,col-1,row-2,dp));
    
    }
int solvetab(int n) {
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(mr,vector<int>(mc,0)));
    for (int row = 0; row < mr; ++row) {
        for (int col = 0; col < mc; ++col) {
            if (mat[row][col] >= 0) {
                dp[0][row][col] = 1;
            }
        }
    }

    vector<int> dr = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> dc = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int idx=1;idx<n;idx++) {
        vector<vector<int>> temp(mr, vector<int>(mc, 0));
        for (int row=0;row<mr;row++) {
            for (int col=0;col<mc;col++) {
                if (mat[row][col]>=0) {
                    for (int k=0; k<8;k++) {
                        int r=row+dr[k];
                        int c=col+dc[k];
                        if (r>=0 && c>=0 && r<mr && c<mc && mat[r][c]>=0) {
                            temp[row][col]=(temp[row][col] + dp[idx-1][r][c])%mod;
                        }
                    }
                }
            }
        }
        dp[idx] = temp;
    }

    int ans = 0;
    for (int row = 0; row < mr; ++row) {
        for (int col = 0; col < mc; ++col) {
            ans = (ans + dp[n - 1][row][col]) % mod;
        }
    }
    return ans;
}

    int knightDialer(int n) {
        int ans=0;
        mat={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(5,vector<int>(4,-1)));
        // ans=(ans+solvetab(n-1))%mod;
        // mr=4,mc=3;
        // for(int i=0;i<9;i++)
        // {
        //     ans=(ans+solvetab(n-1))%mod;
        // }
        return solvetab(n);
    }
};