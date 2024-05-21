class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        int i=0,j=0;
        for(;i<n && j<m;j++){
            if(s[i]==t[j])i++;
        }
        return i==s.size();
    }
    int numMatchingSubseq(string t, vector<string>& words) {
        int ans=0;
        unordered_map<string,int> mp;
        for(auto it:words)mp[it]++;

        for(auto it:mp){
            string s=it.first;
            if(isSubsequence(s,t))ans+=it.second;
        }
        return ans;
    }
};