class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> suf(s.size(),0),pre(s.size(),0);
        for(int i=1;i<s.size();i++){
            pre[i]=pre[i-1];
            if(s[i-1]=='b')pre[i]++;
        }
        vector<int> idx;
        for(int i=s.size()-2;i>=0;i--){
            suf[i]=suf[i+1];
            if(s[i+1]=='a')
                suf[i]++;
            else idx.push_back(i);
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            ans=min(ans,suf[i]+pre[i]);
        }
        // for(auto it:suf)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:pre)cout<<it<<" ";
        return ans;
    }
};