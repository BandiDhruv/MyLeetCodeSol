class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> f(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++)
            for(auto it:words[i])
                f[i][it-'a']++;
        vector<string> ans;
        for(int i=0;i<26;i++){
            int temp=0,cnt=INT_MAX;
            bool ok=false;
            for(int j=0;j<words.size();j++){
                if(f[j][i]==0){ok=true;break;}
                cnt=min(cnt,f[j][i]);
                temp++;
            }
            if(ok)continue;
            if(temp==words.size()){
                while(cnt--){ans.push_back(string(1,'a'+i));}
            }
        }
        return ans;

    }
};