class Solution {
public:
vector<int>vec;
vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>&graph){
        vec.push_back(node);
        if(node==graph.size()-1)
                ans.push_back(vec);
        for(auto it:graph[node]){
                dfs(it,graph);        
        }
        vec.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // vector<int>vis(graph.size());
       dfs(0,graph);
       return ans;
    }
};