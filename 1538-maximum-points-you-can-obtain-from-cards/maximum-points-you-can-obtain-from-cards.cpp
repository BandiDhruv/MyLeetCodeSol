class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int left=0,total=accumulate(nums.begin(),nums.end(),0),ans=INT_MIN,n=nums.size(),cnt=0,sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            cnt++;
            while(cnt>n-k && left<=right){
                sum-=nums[left];
                left++;
                cnt--;
            }
            if(cnt==n-k)
                ans=max(ans,total-sum);
        }
        return ans;
    }
};