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
    int findMaximumXOR(vector<int>& nums) {
        TrieNode*root=new TrieNode();
        for(auto &it:nums)insert(root,it);
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int temp=solve(root,nums[i]);
            maxi=max(maxi,temp);
        }    
        return maxi;
    }
};