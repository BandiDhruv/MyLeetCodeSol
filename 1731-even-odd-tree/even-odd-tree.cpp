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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            // auto node=q.front().first;
            int level=q.front().second;
            int size=q.size();
            // q.pop();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                auto node=q.front().first;
                int level=q.front().second;
                if(node->left)q.push({node->left,level+1});
                if(node->right)q.push({node->right,level+1});
                temp.push_back(node->val);
                q.pop();
            }
            if(level%2==0){
                for(int i=0;i<temp.size()-1;i++)
                {
                    if(temp[i]>=temp[i+1])return false;
                }
            }
            else{
                for(int i=0;i<temp.size()-1;i++)
                {
                    if(temp[i]<=temp[i+1])return false;
                }
            }
            for(int i=0;i<temp.size();i++)
            {
                if(level%2==0){
                    if(temp[i]%2==0)return false;
                }
                else{
                    if(temp[i]%2!=0)return false;
                }
            }
        }
        return true;
    }
};