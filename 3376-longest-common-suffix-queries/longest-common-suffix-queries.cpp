class Solution {
public:
    struct Trie{
        int idx;
        Trie*child[26];
    };
    
    Trie* getNode(int i){
        Trie* temp=new Trie();
        temp->idx=i;
        for(int i=0;i<26;i++){
            temp->child[i]=nullptr;
        }
        return temp;
    }

    void insert(Trie*root,int i,vector<string>&wc){
        string word=wc[i];
        int n=word.size();
        for(int j=n-1;j>=0;j--){
            char ch=word[j];
            int chidx=ch-'a';
            if(root->child[chidx]==nullptr){
                root->child[chidx]=getNode(i);
            }
            root=root->child[chidx];
            if(wc[root->idx].length()>n)root->idx=i;
        }
    }
    int search(Trie*root,string &word){
        int result_idx=root->idx;
        int n=word.size();
        for(int i=n-1;i>=0;i--){
            char ch_idx=word[i]-'a';
            root=root->child[ch_idx];
            if(root==nullptr)return result_idx;
            result_idx=root->idx;
        }
        return result_idx;
    }
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int m=wc.size(),n=wq.size();
        vector<int> ans(n);
        Trie*root=getNode(0);
        for(int i=0;i<m;i++){
            int idx=root->idx;
            if(wc[idx].size()>wc[i].size())root->idx=i;
            insert(root,i,wc);
        }
        for(int i=0;i<n;i++){
            ans[i]=search(root,wq[i]);
        }
        return ans;
    }
};