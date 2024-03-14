class Solution {
public:

vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>&graph,vector<int>& vec){
        vec.push_back(node);
        if(node==graph.size()-1)
                ans.push_back(vec);
        for(auto it:graph[node]){
                dfs(it,graph,vec);        
        }
        vec.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector<int>vis(graph.size());
        vector<int> temp;
       dfs(0,graph,temp);
       return ans;
    }
};