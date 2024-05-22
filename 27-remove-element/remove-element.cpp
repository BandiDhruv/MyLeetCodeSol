class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0,j=nums.size()-1;
        for(int i=0;i<nums.size() && i<=j;i++){
            while(nums[i]==val && i<=j){
                swap(nums[i],nums[j]);
                j--;
                c++;
            }
        }
        
        return nums.size()-c;
    }
};