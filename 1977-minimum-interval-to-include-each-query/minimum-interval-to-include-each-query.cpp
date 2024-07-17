class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans(queries.size(),-1);
        vector<pair<int,int>> qp;
        for(int i=0;i<queries.size();i++){
            qp.push_back({queries[i],i});
        }
        sort(intervals.begin(),intervals.end());
        sort(qp.begin(),qp.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int j=0;
        for(int i=0;i<qp.size();i++){
            int query=qp[i].first;
            while(j<intervals.size() && query>=intervals[j][0]){
                pq.push({intervals[j][1]-intervals[j][0]+1,intervals[j][1]});
                j++;
            }
            while(!pq.empty() && query>pq.top().second){
                pq.pop();
            }
            if(!pq.empty())ans[qp[i].second]=pq.top().first;
        }
        return ans;
    }
};