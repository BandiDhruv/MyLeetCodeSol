class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        set<int>st;
        int maxi=0;
        for(auto it:mp){
            vector<int>vec=it.second;
            int n=vec.size();
            maxi=max(maxi,n);
        }
        for(auto it:mp){
            vector<int>vec=it.second;
            if(maxi-1<vec.size())
            st.insert(vec[maxi-1]);
        }
        string temp="";
        for(auto it:st){
            temp+=s[it];
        }
        return temp;
    }
};