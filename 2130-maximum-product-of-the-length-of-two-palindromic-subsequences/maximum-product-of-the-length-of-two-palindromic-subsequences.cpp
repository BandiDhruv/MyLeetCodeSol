class Solution {
public:
    bool isPal(string &s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int maxProduct(string s) {
        int ans=1;
        vector<pair<int,int>>pr;
        for(int i=0;i<(1<<s.size());i++){
            string temp="";
            for(int j=0;j<s.size();j++){
                if((i&(1<<j))>0){
                    temp.push_back(s[j]);
                }
            }
            if(isPal(temp)){pr.push_back({i,temp.size()});}
        }
        for(int i=0;i<pr.size();i++){
            for(int j=i;j<pr.size();j++){
                int m1=pr[i].first;
                int m2=pr[j].first;
                if((m1&m2)==0)ans=max(ans,pr[i].second*pr[j].second);
            }
        }
        return ans;
    }
};