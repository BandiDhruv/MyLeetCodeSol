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
    void solve(TreeNode*root,string &temp){
        if(!root){
            // temp.push_back(')');
            return;
        }
        temp+=(to_string(root->val));
        if(root->left){
            temp.push_back('(');
            solve(root->left,temp);
            temp.push_back(')');
        }
        else temp+="()";
        if(root->right){
            temp.push_back('(');
            solve(root->right,temp);
            temp.push_back(')');
        }
        
    }
    string tree2str(TreeNode* root) {
        string temp;
        if(root && !root->left && !root->right)return to_string(root->val);
        solve(root,temp);   
        for(int i=0;i<temp.size()-2;i++){
            if(temp[i]=='(' && temp[i+1]==')' && temp[i+2]==')')
            {
                temp.erase(temp.begin()+i,temp.begin()+i+2);
            }
        }

        return temp; 
    }
};