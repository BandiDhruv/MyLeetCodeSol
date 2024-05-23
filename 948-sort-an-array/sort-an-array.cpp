class Solution {
public:
    // mergesort()
    void merge(vector<int>&nums,int i,int j){
        int mid=i+(j-i)/2;
        merge(nums,i,mid);
        merge(nums,mid+1,j);
        // mergesort(nums,i,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)mp[it]++;
        vector<int> ans;
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
        // merge(nums,0,nums.size()-1);
    }
};