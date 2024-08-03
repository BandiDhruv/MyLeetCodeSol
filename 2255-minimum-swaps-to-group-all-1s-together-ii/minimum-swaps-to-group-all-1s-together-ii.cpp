class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp;
        int cnt=0;
        for(auto it:nums)if(it==1)cnt++;
        for(auto it:nums){temp.push_back(it);}
        for(auto it:nums){temp.push_back(it);}
        int window=cnt;
        int left=0;
        int count=0;
        int ans=INT_MAX;
        for(int right=0;right<temp.size();right++){
            if(temp[right]==0)count++;
            while(right-left+1>window && left<=right){
                if(temp[left]==0)count--;
                left++;
            }
            if(right-left+1==window){
                ans=min(ans,count);
            }
        }
        return ans;
    }
};