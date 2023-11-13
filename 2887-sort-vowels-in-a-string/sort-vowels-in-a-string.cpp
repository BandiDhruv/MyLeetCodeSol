class Solution {
public:
    static bool cmp(const char&a,const char&b)
    {
        return (int)a<(int)b;
    }
    string sortVowels(string s) {
        vector<char> temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U')
            {
                temp.push_back(s[i]);
            }
        }
        int k=0;
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U')
            {
                s[i]=temp[k];
                k++;
            }   
        }
        return s;
    }
};