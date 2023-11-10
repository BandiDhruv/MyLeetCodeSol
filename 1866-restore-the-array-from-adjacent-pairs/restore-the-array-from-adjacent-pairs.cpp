class Solution {
public:
           vector<int> ans;
           void dfs(unordered_map<int,vector<int>> &mp,int prev,int start)
           {
               ans.push_back(start);
               for(auto it:mp[start])
               {
                   if(it!=prev)
                   {
                       dfs(mp,start,it);
                   }
               }
           }
           
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
           unordered_map<int,vector<int>> mp;
           for(int i=0;i<adjacentPairs.size();i++)
           {
                mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
                mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
           }
           int start=-1;
           for(auto it:mp)
           {
               if(it.second.size()==1)
               {
                    start=it.first;
                    break;
               }
           }
            dfs(mp,INT_MIN,start);
            return ans;

    }
};