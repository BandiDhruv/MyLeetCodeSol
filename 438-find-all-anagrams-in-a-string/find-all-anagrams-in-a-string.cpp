class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26,0);
        for(auto it:p)mp[it-'a']++;
        int left=0;
        vector<int> ans;
        for(int right=0;right<s.size();right++){
            cout<<left<<" "<<right<<endl;
            mp[s[right]-'a']--;
            int i=0;
            for(;i<26;i++){
                if(mp[i]>0)break;
            }
            if(i==26){
                ans.push_back(left);
                // while(left<=right){
                    mp[s[left]-'a']++;
                    left++;
                // }
            }
            if(right-left+1==p.size()){
                mp[s[left]-'a']++;
                left++;
            }
        }
        return ans;
    }
};