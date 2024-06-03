class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        if(s.size()==1)return 1;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==0)freq[s[i]-'a']++;
            else{
                ans++;
                freq.clear();
                freq.resize(26,0);
                freq[s[i]-'a']++;
            }
        }
        return ans+1;
    }
};