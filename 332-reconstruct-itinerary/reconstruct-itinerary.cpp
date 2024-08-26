class Solution {
public:
    void dfs(vector<string>&ans,unordered_map<string,vector<string>> &mp,string src)
    {
        while(!mp[src].empty()){
            string temp=mp[src].back();
            mp[src].pop_back();
            dfs(ans,mp,temp);
        }
        ans.push_back(src);
        return ;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> mp;
        for(auto it:tickets){
            mp[it[0]].push_back(it[1]);
        }
        for(auto &it:mp){
            sort(it.second.rbegin(),it.second.rend());
        }
        for(auto it:mp){
            cout<<it.first<<" | ";
            for(auto i:it.second)cout<<i<<" ";
            cout<<endl;
        }
        vector<string> ans;
        dfs(ans,mp,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};