class Solution {
public:
    int check(vector<int>&nums,int k){
        if(nums.size()==0)return 0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[i]==k)return 0;
            }
        }
        return 1;
    }
    int solve(vector<int>&nums,int k,vector<int>&temp,int i)
    {
        if(i==nums.size())
            return check(temp,k);
        temp.push_back(nums[i]);
        int pick=solve(nums,k,temp,i+1);
        temp.pop_back();
        pick+=solve(nums,k,temp,i+1);
        return pick;
    
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        return solve(nums,k,temp,0);
    }
};