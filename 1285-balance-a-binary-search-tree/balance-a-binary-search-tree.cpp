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
    void getVec(vector<int> &vals,TreeNode*root){
        if(!root)
            return;
        getVec(vals,root->left);
        vals.push_back(root->val);
        getVec(vals,root->right);
        return;
    }
    TreeNode* getTree(int st,int en,vector<int>&vals){
        if(st>en)
            return nullptr;
        int mid=st+((en-st)>>1);
        return new TreeNode(vals[mid],getTree(st,mid-1,vals),getTree(mid+1,en,vals));    
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        getVec(vals,root);
        int n=(vals.size()-1);
        return getTree(0,n,vals);
    }
};