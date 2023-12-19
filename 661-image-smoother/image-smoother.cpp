class Solution {
public:
        vector<pair<int,int>> vec{
            {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,-1},{-1,0}
        };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size(),m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=img[i][j];
                int cnt=1;
                for(int k=0;k<8;k++)
                {
                    int x=i+vec[k].first;
                    int y=j+vec[k].second;
                    if(x>=0 && y<m && x<n && y>=0)
                    {
                        temp+=img[x][y];
                        cnt++;
                    }
                }
                ans[i][j]=temp/cnt;
            }
        }
        return ans;
    }
};