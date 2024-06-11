class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1,res=1;
        for(int i=1;i<s.size();i++){
            if(s[i]-s[i-1]==1){ans++;res=max(res,ans);}
            else ans=1;
        }
        return res;
    }
};