class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            vector<int> f(26,0);
            for(int j=i;j<s.size();j++){
                f[s[j]-'a']++;
                int maxi=-1,mini=s.size()+1;
                for(int i=0;i<26;i++){
                    maxi=max(maxi,f[i]);
                    if(f[i]!=0){
                        mini=min(mini,f[i]);
                    }
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};