class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> set;
        int count=0;
        for(auto t:s)
            set.insert(t);
        for(auto it:set)
        {
            char a=it;
            int left=-1,right=-1;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==a)
                {
                    if(left==-1)
                        left=i;
                    right=i;
                }
            }
            unordered_set<char> st;
            for(int j=left+1;j<=right-1;j++)
            {
                st.insert(s[j]);
            }
            count+=st.size();
        }
        return count;
    }
};