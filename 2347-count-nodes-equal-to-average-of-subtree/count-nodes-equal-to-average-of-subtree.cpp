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
    void solve(TreeNode* root,int &count)
    {
        int a1=0,a2=0;
        avg(root,a1,a2);
        if(root->val==(a2/a1))
        {
            count++;
            cout<<count<<"  "<<root->val<<endl;
        }
        if(root->left)
            solve(root->left,count);
        if(root->right)
            solve(root->right,count);
    }
    void avg(TreeNode*root,int &count,int &sum){
        // int count=0,sum=0;
        // int temp;
        if(root!=NULL){
            count+=1;
            sum+=root->val;
        }
        else
            return;
        if(root->right)
        {
            // sum+=root->right->val;
            // count++;
            avg(root->right,count,sum);
        }
        if(root->left)
        {
            // sum+=root->left->val;
            // count++;
            avg(root->left,count,sum);
        }
    }
    int averageOfSubtree(TreeNode* root) {
        // TreeNode*temp=root;
        // cout<<avg(root)<<"  "<<solve(root);
        // return solve(root);
        int count=0;
        solve(root,count);
        return count;

    }
};