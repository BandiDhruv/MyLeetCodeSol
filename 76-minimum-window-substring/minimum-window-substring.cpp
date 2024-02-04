class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(t.size()>n)return "";
        unordered_map<char,int> mp;
        for(auto it:t)
        {
            mp[it]++;
        }
        
        int i=0,j=0,ans=INT_MAX,req=t.size(),start=0;
        while(j<n)
        {
            if(mp[s[j]]>0)req--;
            mp[s[j]]--;
            while(req==0)
            {
                int temp=j-i+1;
                if(ans>temp){
                    ans=temp;
                    start=i;    
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)req++;
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)return "";
        return s.substr(start,ans);
    }
};