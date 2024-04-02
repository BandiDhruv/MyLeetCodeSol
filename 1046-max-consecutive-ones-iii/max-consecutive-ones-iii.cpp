class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,n=nums.size();
        int req=k,ans=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0)k--;
            while(k<0 && left<=right){
                cout<<left<<"  "<<right<<endl;
                if(nums[left]==0)k++;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};