class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int > cnt(3,0);
        int left=0,ans=0;
        for(int right=0;right<s.size();right++){
            cnt[s[right]-'a']++;
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                cnt[s[left]-'a']--;
                left++;
                ans+=s.size()-(right);
            }

        }
        return ans;
    }
};