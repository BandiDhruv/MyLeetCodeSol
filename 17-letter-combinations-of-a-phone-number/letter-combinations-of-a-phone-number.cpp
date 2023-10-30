class Solution {
public:
    
    void solve(int cnt,vector<string> &ans,unordered_map<char,string> &mp,string digits,string &ds)
    {
        if(cnt==digits.size())
        {
            ans.push_back(ds);
            return ;
        }
        string t=mp[digits[cnt]];
        for(int i=0;i<t.size();i++)
        {
            ds+=t[i];
            solve(cnt+1,ans,mp,digits,ds);
            ds.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
            vector<string > ans;
        if(digits.size()==0)
            return ans;
            unordered_map<char,string> mp;
            mp['2']="abc";
            mp['3']="def";
            mp['4']="ghi";
            mp['5']="jkl";
            mp['6']="mno";
            mp['7']="pqrs";
            mp['8']="tuv";
            mp['9']="wxyz";
            int cnt=0;

            string ds="";
            solve(cnt,ans,mp,digits,ds);
        return ans;
    }
};