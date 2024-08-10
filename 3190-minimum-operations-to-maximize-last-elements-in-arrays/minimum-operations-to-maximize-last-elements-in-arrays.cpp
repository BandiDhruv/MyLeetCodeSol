class Solution {
public:
    int solve(vector<int>a,vector<int>b){
        int cnt=0,n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]>a[n-1] || b[i]>b[n-1]){
                if(b[i]>a[n-1] || a[i]>b[n-1]){
                    cnt=-1;
                    break;
                }else cnt++;
            }
        }
        return cnt;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans=solve(nums1,nums2);
        if(ans==-1)ans=INT_MAX;
        swap(nums1[nums1.size()-1],nums2[nums1.size()-1]);
        int temp=solve(nums1,nums2);
        if(temp==-1)return -1;
        else return min(ans,temp+1);
    }
};