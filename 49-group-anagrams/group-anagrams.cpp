class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        // vector<string> dup=strs;
        for(int i=0;i<strs.size();i++)
        {
            string d=strs[i];
            // sort(dup[i].begin(),dup[i].end());
            sort(d.begin(),d.end());
            mp[d].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};