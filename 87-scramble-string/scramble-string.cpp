class Solution {
public:
    map<pair<string,string>,bool>mp;
    bool solve(string s1,string s2){
        if(s1 == s2)
            return true;
        if(s1.size()!=s2.size())
            return false;
        if(mp.find({s1,s2})!=mp.end())return mp[{s1,s2}];
        int n=s1.size();
        
        for(int i=1;i<n;i++){
            bool swapped=solve(s1.substr(0,i),s2.substr(n-i,i)) and solve(s1.substr(i,n-i),s2.substr(0,n-i));
            if(swapped)
                return mp[{s1,s2}]=true;
            bool notswapped=solve(s1.substr(i,n-i),s2.substr(i,n-i)) and solve(s1.substr(0,i),s2.substr(0,i));
            if(notswapped)
                return mp[{s1,s2}]=true;
        }
        return mp[{s1,s2}]=false;
        
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};