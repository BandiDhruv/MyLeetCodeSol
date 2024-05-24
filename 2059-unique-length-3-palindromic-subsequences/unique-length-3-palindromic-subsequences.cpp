class Solution {
public:
    int countPalindromicSubsequence(string s){
        int ans=0;
        unordered_set<char> st;
        for(char c:s)
            st.insert(c);
        for(auto it:st){
            int i=-1,j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==it){
                    if(i==-1)i=k;
                    j=k;
                }
            }
            unordered_set<char> temp;
            for(int idx=i+1;idx<j;idx++)temp.insert(s[idx]);
            ans+=temp.size();
        }
        return ans;
    }
};