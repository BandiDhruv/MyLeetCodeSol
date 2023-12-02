class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(int i=0;i<chars.size();i++)
            mp[chars[i]]++;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            unordered_map<char,int> temp;
            int c=0;
            for(auto ch:words[i])
                temp[ch]++;
            for(auto it: temp)
            {
                if(it.second > mp[it.first] )
                {
                    c=1;
                    break;            
                }
            }
            if(c==0)
                ans+=words[i].size();
        }
        return ans;
    }
};