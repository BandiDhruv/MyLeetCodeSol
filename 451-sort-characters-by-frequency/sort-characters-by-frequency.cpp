class Solution {
public:
    static bool cmp(const pair<char,int> &a,const pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto &i:s)mp[i]++;
        vector<pair<char,int>> vp(mp.begin(),mp.end());
        sort(vp.begin(),vp.end(),cmp);
        string ans;
        for(auto it:vp){
            int time=it.second;
            char ch=it.first;
            for(int i=0;i<time;i++)
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};