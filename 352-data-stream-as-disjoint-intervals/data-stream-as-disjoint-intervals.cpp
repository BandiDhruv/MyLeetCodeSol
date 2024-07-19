class SummaryRanges {
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int value) {
        int left  = value;
        int right = value;
        auto just_greater = intervals.upper_bound(value);
        
        if (just_greater != intervals.begin()) {
            
            auto ek_peeche = just_greater;
            --ek_peeche;
            
            if (ek_peeche->second >= value) {
                return;
            }
            if (ek_peeche->second == value - 1) {
                left = ek_peeche->first;
            }
        }
        if (just_greater != intervals.end() && just_greater->first == value + 1) {
            right = just_greater->second;
            intervals.erase(just_greater);
        }
        intervals[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        
        for (const auto& p : intervals) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};