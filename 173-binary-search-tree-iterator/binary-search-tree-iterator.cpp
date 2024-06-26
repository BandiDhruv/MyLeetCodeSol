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
class BSTIterator {
public:
    stack<TreeNode*> ans;
    int idx=0,n;
    void solve(TreeNode*root){
        while(root){
            ans.push(root);
            root=root->left;
        }
        return;
    }
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        auto it=ans.top();
        ans.pop();
        solve(it->right);
        return it->val;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */