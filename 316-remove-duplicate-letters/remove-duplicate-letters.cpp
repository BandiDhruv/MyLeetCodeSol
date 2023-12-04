class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>vis(26,false);
        // vector<char> a;
        string a="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]=i;
        }
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-'a'])continue;
            while(!a.empty() &&  a.back()>s[i] && mp[a.back()]>i)
            {
                vis[a.back()-'a']=false;
                a.pop_back();
            }
            a.push_back(s[i]);
            vis[s[i]-'a']=true;
        }
        // string ans="";
        // for(auto it:a)
            // ans+=it;
        return a;
    }
};