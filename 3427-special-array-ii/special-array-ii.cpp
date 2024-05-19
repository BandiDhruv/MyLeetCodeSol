class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q =queries.size();  
        vector<pair<int,int>> vp;
        for(int i=0;i<n-1;i++){
            if(nums[i]%2==nums[i+1]%2)vp.push_back({i,i+1});
        }
        int m=vp.size();
        vector<bool> ans;
        for(auto it:queries){
            int l=it[0];
            int h=it[1];
            pair<int,int> a={l,0};
            int j=lower_bound(vp.begin(),vp.end(),a)-vp.begin();
            if(j!=m){
                if(h>=vp[j].second)ans.push_back(false);
                else ans.push_back(true);
            }
            else ans.push_back(true);
        }
        return ans;
    }
};