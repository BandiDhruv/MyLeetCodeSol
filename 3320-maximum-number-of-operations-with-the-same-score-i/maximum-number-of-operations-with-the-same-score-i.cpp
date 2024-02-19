class Solution {
public:
    int maxOperations(vector<int>& nums) {
        map<int,int>mp;
        mp[nums[0]+nums[1]]++;
        for(int i=2;i<nums.size();i+=2){
            
              if(mp.find(nums[i]+nums[i+1])!=mp.end())
                    mp[nums[i]+nums[i+1]]++;  
            else
                break;
        }
     
    int ans=0;
        for(auto it:mp){
            cout<<it.first<<" ->"<<it.second<<endl;
            ans=it.second;
        }
        return ans;
        
    }
};