class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0),vis(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']=i;
            // vis[it-'a']++;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(vis[ch-'a']==1)continue;
            if(st.empty() || ch>st.top()){
                st.push(ch);
                vis[ch-'a']=1;
            }
            else{
                while(!st.empty() && st.top()>ch && freq[st.top()-'a']>i){
                    char c=st.top();
                    st.pop();
                    vis[c-'a']=0;
                }
                if(vis[ch-'a']==0){
                    vis[ch-'a']=1;    
                    st.push(ch);
                }
            }
        }
        string temp;
        while(!st.empty()){
            cout<<st.top()<<" ";
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};