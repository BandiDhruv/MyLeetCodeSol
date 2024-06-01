class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> ans;
        if(s.size()<10)return ans;
        for(int i=0;i<=s.size()-10;i++){
            cout<<s.substr(i,10)<<endl;
            mp[s.substr(i,10)]++;
        }
        for(auto it:mp){
            if(it.second>1)ans.push_back(it.first);
        }
        return ans;
    }
};