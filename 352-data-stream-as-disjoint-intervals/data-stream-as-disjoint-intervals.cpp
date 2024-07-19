class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        vector<int>nums(st.begin(),st.end());
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            while(i<nums.size()-1 && nums[i+1]==nums[i]+1)i++;
            ans.push_back({val,nums[i]});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */