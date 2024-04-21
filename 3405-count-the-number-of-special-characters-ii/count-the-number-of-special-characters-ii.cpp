class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='a' && word[i]<='z')
                mp[word[i]]=i;
            else 
            {
                if(mp.find(word[i])==mp.end())
                    mp[word[i]]=i;
            }
        }
        int cnt=0;

        for(char ch='a';ch<='z';ch++){
            if(mp.find(ch)!=mp.end()){
                int temp=mp[ch];
                char h=ch-32;
                int p=-1;
                if(mp.find(h)!=mp.end()){
                    p=mp[h];
                }
                if(p!=-1 && temp<p){cnt++;cout<<ch<<" "<<h<<" "<<p<<" "<<temp<<endl;}
            }
        }
        return cnt;
    }
};