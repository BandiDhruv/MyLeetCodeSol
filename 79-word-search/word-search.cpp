class Solution {
public:
    struct TrieNode{
        unordered_map<char,TrieNode*> mp;
        bool isEnd;
    };
    TrieNode*getNode(){
        TrieNode*root=new TrieNode();
        root->isEnd=false;
        return root;
    }
    void insert(TrieNode*temp,string word){
        TrieNode*root=temp;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(root->mp.find(ch)==root->mp.end())
                root->mp[ch]=getNode();
            root=root->mp[ch];
        }
        root->isEnd=true;
    }
    bool isValid(int x,int y,vector<vector<char>>&board){
        return (x>=0 && y>=0 && x<board.size() && y<board[0].size()); 
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>&board,int i,int j,TrieNode*root,vector<vector<bool>> &vis){
        TrieNode*temp=root;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isValid(x,y,board) && temp->mp.find(board[x][y])!=temp->mp.end() && !vis[x][y]){
                if(dfs(board,x,y,temp->mp[board[x][y]],vis))return true;
            }
        }
        vis[i][j]=false;
        if(temp->isEnd){
            cout<<"s";
            for(auto it:temp->mp){
                if(it.second!=nullptr)return false;
            }
        }
        return temp->isEnd;
    }
    bool exist(vector<vector<char>>& board, string word) {
        TrieNode*root=new TrieNode();
        insert(root,word);
        // for(auto it:board){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(dfs(board,i,j,root->mp[board[i][j]],vis))return true;
                }
            }
        }
        return false;
    }
};