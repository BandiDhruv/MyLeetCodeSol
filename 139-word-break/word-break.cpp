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

    bool isP(TrieNode*t,string s){
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(t->mp.find(ch)==t->mp.end())
                return false;
            t=t->mp[ch];
        }
        return t->isEnd;
    }
    int dp[302];
    bool solve(string s,int i,TrieNode*t){
        if(i>=s.size())
            return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.size();j++){
            if(isP(t,s.substr(i,j+1-i)) && solve(s,j+1,t))
                return dp[i]=true;
        }
        return dp[i]=false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* t=new TrieNode();
        for(auto it:wordDict){
            insert(t,it);
        }
        memset(dp,-1,sizeof(dp));
        return solve(s,0,t);
    }
};