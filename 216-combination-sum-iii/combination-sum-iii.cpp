class Solution {
public:
    void solve(int n,int k,vector<vector<int>>&ans,vector<int>temp,int idx)
    {
        if(temp.size()==k)
        {
            if(n==0)
            {
                ans.push_back(temp);
                return ;
            }
        }
        if(n<0)
            return ;
        for(int i=idx;i<=9;i++)
        {
            temp.push_back(i);
            solve(n-i,k,ans,temp,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,ans,temp,1);
        return ans;
    }
};