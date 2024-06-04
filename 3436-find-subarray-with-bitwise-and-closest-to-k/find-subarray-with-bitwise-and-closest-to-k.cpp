class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        set<int> s1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>s2;
            s2.insert(nums[i]);
            for(auto it:s1){
                s2.insert(it&nums[i]);
            }
            for(auto it:s2){
                ans=min(ans,abs(it-k));
            }
            s1=s2;
        }
        return ans;
    }
};