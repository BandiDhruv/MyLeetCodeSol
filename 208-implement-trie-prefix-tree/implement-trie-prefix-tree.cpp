class Trie {
public:
    struct TrieNode{
        bool isEndOfWord;
        TrieNode*child[26];
    };
    TrieNode* getNode(){
        TrieNode*temp=new TrieNode();
        temp->isEndOfWord=false;
        for(int i=0;i<26;i++)temp->child[i]=NULL;
        return temp;
    }
    Trie() {
        root=getNode();
    }
    TrieNode*root;
    void insert(string word) {
        TrieNode*temp=root;
        for(auto ch:word){
            int idx=ch-'a';
            if(temp->child[idx]==NULL)temp->child[idx]=getNode();
            temp=temp->child[idx];
        }
        temp->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode*temp=root;
        int i=0;
        for(;i<word.size();i++){
            int idx=word[i]-'a';
            if(temp->child[idx]==NULL)return false;
            temp=temp->child[idx];
        }
        if(i==word.size() && temp->isEndOfWord)return true;
        return false;
    }
    
    bool startsWith(string word) {
        TrieNode*temp=root;
        int i=0;
        for(;i<word.size();i++){
            int idx=word[i]-'a';
            if(temp->child[idx]==NULL)return false;
            temp=temp->child[idx];
        }
        if(i==word.size())return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */