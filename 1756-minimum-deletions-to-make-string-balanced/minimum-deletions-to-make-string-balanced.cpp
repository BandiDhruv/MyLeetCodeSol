class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a')st.push('a');
            else {
                if(st.empty())continue;
                else if(st.top()=='a'){
                    cout<<i<<"  ";
                    st.pop();
                    ans++;
                }
            }
        }
        return ans;
    }
};