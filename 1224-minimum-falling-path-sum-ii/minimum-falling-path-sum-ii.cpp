class Solution {
public:
    int t[201][201];
    int solve(int idx ,int last,vector<vector<int>>& grid){
        if ( idx >= grid.size() ) return 0;
        if ( last != -1  && t[idx][last] != -1 ) return t[idx][last];
        int ans = 0;
        int curr = INT_MAX;
        for(int i = 0 ; i < grid[idx].size() ; i++){
            int now = 0;
            if ( last == -1 || i != last){
                now = grid[idx][i] + solve(idx+1,i,grid);
                curr = min(curr,now);
            }
        }
        ans = curr;
        if ( last != -1 ) t[idx][last] = ans;
        return ans;

    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,grid);
    }
};