class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans=0;
        map<int,map<int,int>> mp;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for(int j=0;j<s.size();j++){
                mp[j][s[j]-'0']++;
            }
        }
        int n=nums.size();
        for(auto it:nums){
            string temp=to_string(it);
            long long cnt=0;
            for(int i=0;i<temp.size();i++){
                cnt+=n-mp[i][temp[i]-'0'];
            }
            ans+=cnt;
        }
        return ans/2;
    }
};