class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        vector<pair<char, int>> freqPairs(mp.begin(), mp.end());
        sort(freqPairs.begin(), freqPairs.end(), cmp);

        string ans;
        for (auto& pair : freqPairs) {
            ans += string(pair.second, pair.first);
        }

        return ans;
    }
};
