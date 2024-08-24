class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans;
        deque<pair<char,int>> dq;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string temp="";
                while(st.top()!="["){
                    temp+=(st.top());
                    st.pop();
                }
                st.pop();
                if(dq.empty())continue;
                int idx=dq.back().second;
                char t=dq.back().first;
                string hello;
                hello.push_back(t);
                dq.pop_back();
                while(!dq.empty() && idx==dq.back().second+1){
                    hello.push_back(dq.back().first);
                    idx=dq.back().second;
                    dq.pop_back();
                }
                reverse(hello.begin(),hello.end());
                int tt=stoi(hello);
                string hi=temp;
                cout<<tt<<" "<<hello<<endl;
                for(int j=0;j<tt-1;j++)
                    temp+=hi;
                st.push(temp);
            }
            else if(s[i]<='9' && s[i]>='0')
                dq.push_back({s[i],i});
            else 
                st.push(string(1,s[i]));
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};