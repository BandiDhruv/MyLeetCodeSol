class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int peak=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(peak==0){
                    peak=1;
                    if(i-1>=0 && nums[i-1]>nums[i+1] )
                        nums[i+1]=nums[i];
                    else nums[i]=nums[i+1];
                }
                else return false;
            }   
        }
        return true;
    }
};