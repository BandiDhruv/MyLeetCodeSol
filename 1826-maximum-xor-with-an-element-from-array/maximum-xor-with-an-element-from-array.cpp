class Solution {
public:
     struct TrieNode{
        TrieNode*left;
        TrieNode*right;
    };
    void insert(TrieNode*root,int &num){
        TrieNode* temp=root;
        for(int i=31;i>=0;i--){
            int ibit=(num>>i)&1;
            if(ibit==0){
                if(temp->left==NULL)temp->left=new TrieNode();
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)temp->right=new TrieNode();
                temp=temp->right;
            }
        }
        return ;
    }
    int solve(TrieNode*root,int &num){
        int ans=0;
        TrieNode*temp=root;
        for(int i=31;i>=0;i--){
            int ibit=(num>>i)&1;
            if(temp==nullptr)break;
            if(ibit==1){
                if(temp->left!=nullptr)
                {
                    ans+=pow(2,i)*1;
                    temp=temp->left;
                }
                else{
                    ans+=pow(2,i)*0;
                    temp=temp->right;
                }
            }
            else{
                if(temp->right!=nullptr)
                {
                    ans+=pow(2,i)*1;
                    temp=temp->right;
                }
                else{
                    ans+=pow(2,i)*0;
                    temp=temp->left;
                }
            }
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> que;
        
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            que.push_back({b,a,i});
        }

        sort(que.begin(),que.end());
        int i=0;
        TrieNode*root=new TrieNode();
        vector<int> temp;
        for(auto it:que){
            int idx=it[2];
            int num=it[1];
            int maxi=it[0];
            while(i<nums.size()){
                if(nums[i]<=maxi)insert(root,nums[i]);
                else break;
                i++;
            }
            if(i==0)ans[idx]=-1;
            else
                ans[idx]=solve(root,num);
        }
        return ans;
    }
};