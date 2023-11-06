class Solution {
public:
    unordered_set<string> st;
    bool solve(string s,int idx)
    {
        if(idx==s.size())
            return true;
        if(st.find(s)!=st.end())
            return true;
        for(int i=1;i<s.size();i++)
        {
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(s,idx+i))
                return true;
        }
        return false;
    }
    bool solvemem(string s,int idx,vector<int>&dp)
    {
        if(idx==s.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        if(st.find(s)!=st.end())
            return true;
        for(int i=1;i<s.size();i++)
        {
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end() && solvemem(s,idx+i,dp))
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // string temp="";
        // if(wordDict[0]==s)
            // return true;
        // return solve(s,wordDict,0,temp);
        // return true;
        for(auto it:wordDict)
        {
            st.insert(it);
        }
        // return solve(s,0);
        vector<int> dp(s.size()+1,-1);
        return solvemem(s,0,dp);
    }
};