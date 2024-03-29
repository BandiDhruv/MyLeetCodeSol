class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int left=0;
        map<int , long long > mp;
        long long maxi=*max_element(nums.begin(),nums.end())*1ll;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(mp[maxi]>=k){
                ans+=nums.size()-right;
                cout<<right<<"  "<<left<<endl;
                mp[nums[left]]--;
                left++;
            }
        }
        return ans;
    }
};