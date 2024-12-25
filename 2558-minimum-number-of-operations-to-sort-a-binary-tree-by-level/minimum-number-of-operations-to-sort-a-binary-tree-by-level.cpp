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
    int minSwaps(int n,vector<int>& a)
    {
        pair<int, int> p[n];
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            p[i].first = a[i];
            p[i].second = i;
        }        
        sort(p, p+n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {	
            if (visited[i] || p[i].second == i)
                continue;    
            int cycle_size = 0;
            int j = i;
            while (!visited[j])
            {
                visited[j] = 1;
                j = p[j].second;
                cycle_size++;
            }
            ans += (cycle_size - 1);
        }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return 0;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>a;
            for(int i=0;i<size;i++){
                auto it=q.front();
                a.push_back(it->val);
                q.pop();
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
            cnt+=minSwaps(a.size(),a);
        }    
        return cnt;
    }
};