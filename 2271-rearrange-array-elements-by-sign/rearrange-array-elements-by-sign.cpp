class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int i=0,j=1;
        vector<int> ans1,ans2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)ans1.push_back(nums[i]);
            else ans2.push_back(nums[i]);
        }
        // vector<int> ans;
        int cnt=0;
        for(int i=0;i<nums.size()/2;i++){
            nums[cnt]=ans2[i];
            cnt++;
            nums[cnt]=ans1[i];
            cnt++;
        }
        return nums;
    }
};