class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)mat[i][j]=0;
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        int ans=n+1;
        int city=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] <=t)
                {
                    cnt++;
                }
            }
            if(ans>=cnt)
            {
                ans=cnt;
                city=i;
            }
        }
        return city;
    }
};