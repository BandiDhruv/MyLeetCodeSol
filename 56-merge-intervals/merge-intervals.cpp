class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
        return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        // result.push_back({intervals[0][0],intervals[0][1]});
        // or
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(result.back()[1]>=intervals[i][0])
            {
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }
            else
            {
                result.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return result;
    }
};