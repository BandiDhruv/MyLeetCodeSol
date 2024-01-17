class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i:arr)mp[i]++;
        set<int>s ;
        for(auto i:mp)s.insert(i.second);
        return s.size()==mp.size();
    }
};