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

    int countDays(int d, vector<vector<int>>& s) {
        if(s.size()==1)return (d-(s[0][1]-s[0][0]+1));
        vector<vector<int>> temp=merge(s);
        int last=temp[0][1];
        for(auto it:temp)cout<<it[0]<<" "<<it[1]<<endl;
        long long cnt=temp[0][1]-temp[0][0]+1;
        if(temp.size()<=1)return d-cnt;
        for(int i=1;i<temp.size();i++){
            cnt+=1ll*(temp[i][1]-temp[i][0]+1);
            if(last==temp[i][0])cnt--;
            last=temp[i][1];
        }
        int ans=d-cnt;
        if(ans<0)return 0;
        return ans;
    }
};