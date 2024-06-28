class Solution {
public:
    int maxVowels(string s, int k) {
        int left=0,ans=INT_MIN;
        map<char,int> mp;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            while(right-left+1>k){
                mp[s[left]]--;
                left++;
            }
            if(right-left+1==k){
                ans=max(ans,mp['a']+mp['e']+mp['i']+mp['o']+mp['u']);
            }
        }
        return ans;
    }
};