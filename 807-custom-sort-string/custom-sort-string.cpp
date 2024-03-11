class Solution {
public:
    string customSortString(string o, string s) {
        map<char,int> mp1,mp2;
        for(int i=0;i<o.size();i++)mp1[o[i]]++;
        for(int i=0;i<s.size();i++)mp2[s[i]]++;
        string temp;
        for(int i=0;i<o.size();i++)
        {
            if(mp2.find(o[i])==mp2.end()){
                continue;
            }
            else {
                for(int j=0;j<mp2[o[i]];j++)temp.push_back(o[i]);
            }
        }
        for(auto it:mp2)
        {
            bool f=false;
            for(auto i:temp)
            {
                if(i==it.first){
                    f=true;
                    break;
                }
            }
            if(!f){
                for(int i=0;i<it.second;i++)
                    temp.push_back(it.first);
            }
        }

        return temp;
    }
};