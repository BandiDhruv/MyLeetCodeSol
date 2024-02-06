class Solution {
public:

    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&t)
    {
        if(j-i<2)return 0;//very imp base condition kabhi nahi soch pataaa
        if(t[i][j]!=-1)return t[i][j];
        int res=1e9;
        for(int idx=i+1;idx<j;idx++)
        {
            int temp=cuts[j]-cuts[i]+solve(i,idx,cuts,t)+solve(idx,j,cuts,t);
            res=min(res,temp);
        }
        return t[i][j]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> t(103,vector<int>(103,-1));
        return solve(0,cuts.size()-1,cuts,t);
    }
};