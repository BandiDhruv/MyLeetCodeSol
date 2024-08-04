class Solution {
public:
    map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        if(s1==s2)
            return true;
        string key=s1+"_"+s2;
        bool flag=false;
        if(mp.find(key)!=mp.end())
            return mp[key];
        for(int i=1;i<s1.size();i++){
            bool op1=isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(i,s1.size()-i));
            bool op2=isScramble(s1.substr(0,i),s2.substr(s1.size()-i,i)) && isScramble(s1.substr(i,s1.size()-i),s2.substr(0,s1.size()-i));
            if(op1 || op2){
                flag=true;
                break;
            }
        }    
        return mp[key]=flag;
    }
};