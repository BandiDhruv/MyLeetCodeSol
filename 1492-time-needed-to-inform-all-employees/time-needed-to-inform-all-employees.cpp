class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& it) {
        if(n==1)return 0;
        map<int,vector<int>> mp;
        queue<int> q;
        int ans=0;
        vector<int> sum(n,0);
        sum[headID]=0;
        for(int i=0;i<m.size();i++){
            if(i==headID)
                q.push(i);
            else
                mp[m[i]].push_back(i);
        }
//             0
//         /       \
//        1          2
//     /   \       /    \
//    3     4     5      6
//  /   \  / \   /  \    / \
//  7    8 9 10 11   12 13  14
 
 
 
       while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                for(auto x:mp[node]){
                    sum[x]=sum[node]+it[node];
                    q.push(x);
                }
            }
        }
        for(int i=0;i<n;i++)
            ans=max(ans,sum[i]);
        return ans;
    }
};