/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                adj[temp->val].push_back(temp->left->val);
                adj[temp->left->val].push_back(temp->val);
            }
            if (temp->right) {
                q.push(temp->right);
                adj[temp->val].push_back(temp->right->val);
                adj[temp->right->val].push_back(temp->val);
            }
        }
        queue<pair<int, pair<int, int>>> qe;
        qe.push({start, {-1, 0}});
        int ans = 0;
        while (!qe.empty()) {
            int val = qe.front().first;
            int parent = qe.front().second.first;
            int level = qe.front().second.second;
            ans = level;
            qe.pop();
            for (auto it : adj[val]) {
                if (it == parent)
                    continue;
                qe.push({it, {val, level + 1}});
            }
        }
        return ans;
    }
};