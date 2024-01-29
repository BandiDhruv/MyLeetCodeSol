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
    // bool isPalindrome(string a)
    // {
    //     unordered_map<char,int> mp;
    //     for(int i=0;i<a.size();i++)
    //         mp[a[i]]++;
    //     if(a.size()%2==0)
    //     {
    //         for(auto it:mp)
    //         {
    //             if(it.second%2!=0)return false;
    //         }
    //     }
    //     else{
    //         int am=0;
    //         for(auto it:mp)
    //             if(it.second%2!=0)am++;
    //         return am==1;
    //     }
    //     return true;
    // }
    int ans=0;
    void solve(TreeNode*root, vector<int>&temp)
    {
        if(root==NULL)return ;
        // string temp;
        // int ans=0;
        temp[root->val]++;
        if(root->left==NULL && root->right==NULL ){
            int oddC=0;
            for(int i=0;i<=9;i++)
            {
                if((temp[i])&1)oddC++;
            }
            if(oddC<=1) ans++;
            
        }
        
        if(root->left) solve(root->left,temp);
        if(root->right)solve(root->right,temp);
        temp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->left==NULL && root->right==NULL)return 1;
        // string temp=to_string(root->val);

        vector<int>temp(10,0);
        solve(root,temp);
        // solve(root->right,temp);
        return ans;    
    }
};