class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        vector<bool> ok(s.size(),false);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({s[i],i});
            }else if(s[i]==')'){
                if(!st.empty()){
                    auto it=st.top();
                    ok[it.second]=true;
                    ok[i]=true;
                    st.pop();
                }
            }
        }
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==')'){
                if(ok[i]){
                    ans.push_back(s[i]);
                }
            }
            else  ans.push_back(s[i]);
        }
        return ans;
    }
};