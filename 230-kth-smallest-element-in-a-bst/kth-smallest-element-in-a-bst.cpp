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
    // int cntNodes(TreeNode*temp){
    //     if(!temp)return 0;
    //     int ans=0;
    //     if(temp->left){
    //         ans+=1+cntNodes(temp->left);
    //     }
    //     if(temp->right){
    //         ans+=1+cntNodes(temp->right);
    //     }
    //     return ans;
    // }
    void solve(vector<int>&ans,TreeNode*root){
        if(!root)return;
        if(root->left)solve(ans,root->left);
        ans.push_back(root->val);
        if(root->right)solve(ans,root->right);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp=root;
        vector<int> ans;
        // int n=cntNodes(temp)+1;
        // int leftcnt=cntNodes(temp->left)+1;
        // int rightcnt=cntNodes(temp->right)+1;
        // // cout<<n<<" "<<leftcnt<<" "<<rightcnt<<endl;
        // int ans=-1;
        // if(k<=leftcnt){
        //     ans=solve(root->left,k);
        // }
        // else if(k>leftcnt){
        //     if(k==leftcnt+1)return root->val;
        //     else ans=solve(root->right,k-leftcnt+1);
        // }
        // return ans;
        solve(ans,root);
        // for(auto it:ans)cout<<it;
        return ans[k-1];
    }
};