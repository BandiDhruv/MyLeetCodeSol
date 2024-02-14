class Solution {
public:
    vector<int> rotate(vector<int>&ans,int s){
        int idx=0,n=ans.size();
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==s){
                idx=i;
                break;
            }
        }
        vector<int> temp;
        for(int i=idx;i<n;i++)
        {
            temp.push_back(ans[i]);
        }
        for(int i=0;i<idx;i++)
        {
            temp.push_back(ans[i]);
        }

        return temp;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int>ans;
        for(int i=0;i<(1<<n);i++){
            ans.push_back(i^(i>>1));
        }
         return rotate(ans,start);
    }
};