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
 #include<bits/stdc++.h>
class Solution {
public:
    unordered_map<int,int> mp;
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        if(root->left)
            solve(root->left);
        if(root->right)
            solve(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        // unordered_map<int,int> mp;
        // if(root!=NULL)
        //     mp[root->val]++;
        solve(root);
        // sort(mp.begin(),mp.end(),greater<int>());
        int maxi=INT_MIN;
        for(auto it:mp)
        {
            maxi=max(it.second,maxi);
        }
        for(auto it:mp)
        {
            if(maxi==it.second)
                ans.push_back(it.first);
        }
        // while(mp[i]==mp[i+1]){
        //     ans.push_back(mp[i]);
        //     i++;
        // }
        return ans;
        
    }
};