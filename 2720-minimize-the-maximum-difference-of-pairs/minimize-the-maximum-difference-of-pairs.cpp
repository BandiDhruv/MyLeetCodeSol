class Solution {
public:
    int n;
    bool solve(vector<int>&nums,int p,int mid){
        int in=0,cnt=0;
        cout<<endl<<mid<<endl;
        for( int i = 1 ; i < n ; i++ ){
            if(in)
            {   in=0;
                continue;
            }
            if(abs(nums[i]-nums[i-1])<=mid){
                in=1;
                cnt++;
            }
            if(cnt>=p)return true;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums[n-1]-nums[0],ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(solve(nums,p,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};