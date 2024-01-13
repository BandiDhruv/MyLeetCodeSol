class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        unordered_map<char,int> map;
        for(auto it:s) mp[it]++;
        for(auto it:t) map[it]++;

        int cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(map.find(it->first)!=map.end()){
                int freq=map[it->first];
                if(freq<it->second) cnt+=it->second-freq;
            }   
                  else cnt+=it->second;
        }
        return cnt;
    }
};