class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size()==0)return 0;
        int left=0;
        map<char,int> f;
        int ans=0;
        bool ok=true;
        for(int right=0;right<s.size();right++){
            f[s[right]]++;
            for(auto it:f){
                if(it.second>1){
                   ok=false;
                   break;
                }
            }
            while(!ok && left<=right){
                f[s[left]]--;
                left++;
                ok=true;
                for(auto it:f){
                    if(it.second>1){
                        ok=false;
                        break;
                    }
                }
                if(ok)break;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};