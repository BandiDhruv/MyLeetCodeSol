class Solution {
public:
    int minimumDeletions(string s) {
        // vector<int> suf(s.size(),0),pre(s.size(),0);
        int acount=0,bcount=0;
        // for(int i=s.size()-2;i>=0;i--){
        //     suf[i]=suf[i+1];
        //     if(s[i+1]=='a')
        //         suf[i]++;
        // }
        // int ans=suf[0]+pre[0];
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            //  pre[i]=pre[i-1];
            // if(s[i-1]=='b')pre[i]++;
            // ans=min(ans,suf[i]+pre[i]);
            if(s[i]=='a')acount++;
        }
        if(s.size()==acount)return 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')acount--;
            ans=min(ans,acount+bcount);
            if(s[i]=='b')bcount++;
            // else acount--;
        }
        return ans;
    }
};