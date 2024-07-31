class Solution {
public:
    void mergesort(vector<int>&nums,int l,int mid,int h){
        int s=l,e=mid+1;
        vector<int> temp;
        while(s<=mid && e<=h){
            if(nums[s]>nums[e])
                temp.push_back(nums[e++]);
            else
                temp.push_back(nums[s++]);
        }
        while(s<=mid)temp.push_back(nums[s++]);
        while(e<=h)temp.push_back(nums[e++]);
        for (int i=l; i<=h;i++) {
            nums[i]=temp[i-l];
        }
        return;
    }
    void merge(vector<int>&nums,int l,int h){
        if(l>=h)return;
        int mid=(l+h)/2;
        merge(nums,l,mid);
        merge(nums,mid+1,h);
        mergesort(nums,l,mid,h);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};