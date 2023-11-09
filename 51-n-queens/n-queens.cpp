class Solution {
public:
    bool isSafe(int row,int col,vector<string>&temp,int n)
    {
        int duprow=row,dupcol=col;
        while(row>=0 && col >=0)
        {
            if(temp[row][col]=='Q')
            {
                return false;
            }
                row--;col--;
        }
        row=duprow,col=dupcol;
        while(row<n && col >=0)
        {
            if(temp[row][col]=='Q')
            {
                return false;
            }
                row++;col--;
        }
        row=duprow,col=dupcol;
        while(col>=0)
        {
            if(temp[row][col]=='Q')
                return false;
            col--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>> &ans,vector<string>&temp,int n)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,temp,n))
            {
                temp[i][col]='Q';
                solve(col+1,ans,temp,n);
                temp[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string a(n,'.');
        for(int i=0;i<n;i++)
        {
            temp[i]=a;
        }
        solve(0,ans,temp,n);
        return ans;
    }
};