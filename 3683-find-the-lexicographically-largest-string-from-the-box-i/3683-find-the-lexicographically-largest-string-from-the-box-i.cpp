class Solution {
public:
    string answerString(string s, int k) {
        vector<int> f(26,0);
        if(k==1)
            return s;
        int n=s.size();
        for(auto it:s)f[it-'a']++;
        int idx;
        for(idx=25;idx>=0;idx--)if(f[idx]!=0)break;
        char ch = idx+'a';
        vector<int> ind ;
        for(int i=0;i<n;i++){
            if(ch == s[i])ind.push_back(i);
        }
        int len = n-k+1;
        string ans="";
        for(int i=0;i<ind.size();i++){
            // int remLen = n-ind[i];
            // if(remLen>=len)
            // {
                string temp=s.substr(ind[i], len);
                // if(temp>ans) 
                    ans=max(ans,temp);
            // }
        }
        // for(auto it:st)
            // ans=it;
            // cout<<it<<endl;
        return ans;
    }
};