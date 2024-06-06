class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m=1e9+7,l=0,n=nums.size(),r=n-1,ans=0;
        vector<int> po(n+1);
        po[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++){
            po[i]=(po[i-1]*2)%m;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target)
            {
                ans+=po[r-l];
                ans%=m;
                l++;
            }
            else r--;
        }
        return ans;

    }
};