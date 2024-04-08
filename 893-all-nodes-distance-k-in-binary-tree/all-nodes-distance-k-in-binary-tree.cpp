/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*root,map<int,vector<int>>& mp){
        if(!root)return ;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        solve(root->right,mp);
        solve(root->left,mp);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,vector<int>> mp;
        solve(root,mp);
        // for(auto it:mp){
        //     cout<<it.first<<"->";
        //     for(auto i:it.second)cout<<i<<" ";
        //     cout<<endl;
        // }
        queue<pair<int,int>> q;
        int parent=-1;
        q.push({target->val,-1});
        while(!q.empty() && k>0){
            k--; 
            int size=q.size();
            for(int i=0;i<size;i++){
            int node=q.front().first;
            int par=q.front().second;
                q.pop();
                for(auto it:mp[node]){
                    if(it==par){
                        continue;
                    }
                    cout<<it<<" "<<node<<endl;
                    q.push({it,node});
                }
            }
        }
        vector<int> ans;
        if(k==0){
            while(!q.empty()){
                ans.push_back(q.front().first);
                q.pop();
            }
        }
        
        return ans;
    }
};