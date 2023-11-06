// class Solution {
// public:
//     vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1}};
//     bool find(vector<vector<char>> &board,int i,int j,int idx,string word)
//     {
//         if(idx==word.length())
//             return true;
//         if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$')
//             return false;
//         if(board[i][j]!=word[idx])
//             return false;
//             char temp=board[i][j];
//             board[i][j]='$';
//         for(auto it:dir)
//         {
//             int i_=i+it[0];
//             int j_=j+it[1];
//             if(find(board,i_,j_,idx+1,word))return true;
//         }
//         board[i][j]=temp;
//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int m=board.size(),n=board[0].size();
//             if(m*n<word.length())
//                 return false;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(board[i][j]==word[0] && find(board,i,j,0,word))
//                     return true;
//             }
//         }
//         return false;

//     }
// };
class Solution {
public:
    int l, m, n;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx) {
        if(idx >= l)
            return true;
        
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(find(board, i_, j_, word, idx+1))
                return true;
        }
        
        board[i][j] = temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.length();
        if(m*n < l)
            return false;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};