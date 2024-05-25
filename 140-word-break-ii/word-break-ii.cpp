class Solution {
public:
    void solve(string s,unordered_set<string>&w,vector<string>&ans,string &temp,int i){
        if(i>=s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int idx=i+1;idx<=s.size();idx++){
            string hi=s.substr(i,idx-i);
            if(w.find(hi)!=w.end()){
                string tempo=temp;
                if(!temp.empty())temp+=" ";
                temp+=hi;
                solve(s,w,ans,temp,idx);
                temp=tempo;
            }
        }
        return ;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp;
        unordered_set<string> worddict(wordDict.begin(),wordDict.end());
        solve(s,worddict,ans,temp,0);
        // vector<string> res(ans.begin(),ans.end());
        return ans;
    }
};