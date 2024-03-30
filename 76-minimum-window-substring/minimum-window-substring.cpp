class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        for(auto it:t)mp[it]++;
        int start,ans=INT_MAX,left=0,req=t.size();
        for(int right=0;right<s.size();right++){
            if(mp[s[right]]>0){
                req--;
            }
            mp[s[right]]--;
            while(req==0){
                int wsize=right-left+1;
                if(wsize<ans){
                    ans=wsize;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0)req++;
                left++;
            }

        }
        return ans==INT_MAX?"":s.substr(start,ans);
    }
};