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
    // void nodeCount(TreeNode*root,int &count,unordered_map<int,bool> &mp)
    // {
    //     if(!root && !root->left && !root->right)return ;
    //     if(root->left) {
    //     count++;
    //     mp[root->left->val]=false;
    //     nodeCount(root->left,count,mp);
    //     }
    //     if(root->right){
    //         mp[root->right->val]=false;
    //     count++;    
    //     nodeCount(root->right,count,mp);
    //     } 

    // }
    int amountOfTime(TreeNode* root, int start) {
        int count=1;
        // unordered_map<int,bool> mp;
        // nodeCount(root,count,mp);
        // mp[root->val]=false;
        // cout<<count;
        // for(auto it:mp)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        unordered_map<int,set<int>>adj;
        // TreeNode*temp=root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                adj[temp->val].insert(temp->left->val);
                adj[temp->left->val].insert(temp->val);
            }
            if(temp->right){
                q.push(temp->right);
                adj[temp->val].insert(temp->right->val);
                adj[temp->right->val].insert(temp->val);
            }
        }
        // for(auto i:adj){
        //     for(auto it:i.second)
        //     {
        //         cout<<i.first<<"->"<<it<<endl;
        //     }
        // }
        
        queue<pair<int,pair<int,int>>> qe;
        qe.push({start,{-1,0}});
        int ans=0;
        while(!qe.empty())
        {
            
            int val=qe.front().first;
            int parent=qe.front().second.first;
            int level=qe.front().second.second;
            ans=level;
            // int size=q.size();
            qe.pop();
            // for(int i=0;i<size;i++)
            // {
                for(auto it:adj[val])
                {
                    // if(mp[it]==0)
                    // {
                        cout<<it<<"  ->"<<endl;
                        if(it==parent)continue;
                        // mp[it]=1;
                        qe.push({it,{val,level+1}});
                    // }
                }
                // qe.push({})
            // }
        }

        return ans;      
        
    }
};