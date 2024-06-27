class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0;
        vector<int> f(26,0);
        for(int right=0;right<s2.size();right++){
            f[s2[right]-'a']++;
            while(right-left+1>s1.size()){
                f[s2[left]-'a']--;
                left++;
            }
            if(right-left+1==s1.size()){
                bool ok=true;
                vector<int> temp=f;
                for(int i=0;i<s1.size();i++){
                    if(f[s1[i]-'a']==0){
                        ok=false;
                        break;
                    }
                    f[s1[i]-'a']--;
                }
                f=temp;
                if(ok)return true;
            }
        }
        return false;
    }
};