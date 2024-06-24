class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int currentFlip=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(i>=k){
                if(nums[i-k]==2)currentFlip--;
            }
            if((currentFlip+nums[i])%2==0){
                if(i+k>n)return -1;
                currentFlip++;
                nums[i]=2;
                ans++;
            }
        }
        return ans;
    }
};