class Solution {
public:
    int n,m;
    int dir[8][2]={{0,1},{-1,-1},{-1,0},{1,0},{1,-1},{-1,1},{1,1},{0,-1}};
    map<int,int>mp;
    bool isP(int a)
    {
        if (a<= 1)
            return false;
        for (int i = 2; i <= a / 2; i++)
            if (a% i == 0)
                return false;
        return true;
    }
    void solve(vector<vector<int>>& mat,int i,int j,int k,int c,string &temp)
    {
        if(i>=n || j>=m || i<0 || j<0) return ;
        // int temp=0;
        // temp=temp*c+mat[i][j];
        temp.push_back('0'+mat[i][j]);
        int x=stoi(temp);
        if(x>10 && isP(x)) mp[x]++;
        solve(mat,i+dir[k][0],j+dir[k][1],k,c*10,temp);
        // temp=temp*c-mat[i][j];
        // return ans;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        n=mat.size(),m=mat[0].size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<8;k++)
                {
                    string temp;
                    solve(mat,i,j,k,1,temp);
                }
            }
        }
        for(auto &it:mp)
        {
            ans=max(ans,it.second);
        }
        int res=0;
        for(auto &i:mp)
        {
            if(i.second==ans)res=max(res,i.first);
        }
        return res==0?-1:res;
    }
};