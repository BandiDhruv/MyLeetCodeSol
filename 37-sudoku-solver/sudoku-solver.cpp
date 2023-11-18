class Solution {
public:
    bool isPossible(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int x=0;x<board.size();x++)
        {
            for(int y=0;y<board[0].size();y++)
            {
                if(board[x][y]=='.')
                {
                    for(char num='1';num<='9';num++)
                    {
                        if(isPossible(board,x,y,num))
                        {
                            board[x][y]=num;
                            if(solve(board)==true)
                                return true;
                            else
                                board[x][y]='.';    
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        // int a=1;
        // char b=1;
        // cout<<(char)b;
        
    }
};