/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<TreeNode*> leafN;
    unordered_map<TreeNode*,vector<TreeNode*>>adj;
    void solve(TreeNode*root,TreeNode*prev){
        if(!root)
            return;
        if(!(root->left) && !(root->right)){
            leafN.insert(root);
        }
        if(prev){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        
        solve(root->left,root);
        solve(root->right,root);
    }

    int countPairs(TreeNode* roots, int distance) {
        TreeNode*root=roots;
        solve(root,nullptr);
        int ans=0;
        for(auto &it:leafN){
            cout<<it->val<<endl;
            queue<TreeNode*> q;
            unordered_set<TreeNode*> seen;
            q.push(it);
            seen.insert(it);
            for(int i=0;i<=distance;i++){
                int siz=q.size();
                while(siz--){
                    TreeNode*curr=q.front();
                    q.pop();
                    if((leafN.find(curr)!=leafN.end()) && (curr!=it))
                        ans++;
                    for(TreeNode* its:adj[curr]){
                        if(seen.find(its)==seen.end()){
                            q.push(its);
                            seen.insert(its);
                        }
                    }
                }
            }
        }
        return ans/2;
    }
};