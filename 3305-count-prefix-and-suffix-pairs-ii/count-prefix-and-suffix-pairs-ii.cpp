class Solution {
public:
    long long ans=0;
    struct TrieNode{
        map<pair<char,char>,TrieNode*> child;
        int count=0;
    };

    void insert(string a,TrieNode* root){
        TrieNode*temp=root;
        for(int i=0;i<a.size();i++){
            char ch1=a[i];
            char ch2=a[a.size()-i-1];
            if(temp->child.find({ch1,ch2})==temp->child.end())temp->child[{ch1,ch2}]=new TrieNode();
            temp=temp->child[{ch1,ch2}];
            ans+=temp->count;
        }
        temp->count++;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode*root=new TrieNode();
        for(int i=0;i<words.size();i++){
            insert(words[i],root);
        }
        return ans;

    }
};