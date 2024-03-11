class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==0 && i>l){swap(nums[i],nums[l]);l++;i--;}
            else if(nums[i]==2 && r>i){swap(nums[i],nums[r]);r--;i--;}
            i++;
        }
        return ;
    }
};