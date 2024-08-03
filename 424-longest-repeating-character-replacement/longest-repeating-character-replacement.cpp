class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> f(26,0);
        int left=0,ans=0;
        for(int right=0;right<s.size();right++){
            f[s[right]-'A']++;
            int maxi=INT_MIN;
            for(int i=0;i<26;i++){
                maxi=max(f[i],maxi);
            }
            // int size=right-left+1;
            // int change=size-maxi;
            while(k-(right-left+1-maxi)<0 && left<=right){
                f[s[left]-'A']--;
                left++;
                for(int i=0;i<26;i++){
                    maxi=max(f[i],maxi);
                }
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};