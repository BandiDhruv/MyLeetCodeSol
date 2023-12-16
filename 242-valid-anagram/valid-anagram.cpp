class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(a[t[i]-'a']>0)
            {
                a[t[i]-'a']--;
                c++;
            }
            else return false;
        }
        return (c==s.size());

    }
};