class Solution {
public:
typedef pair<long long ,int> P;
    int mostBooked(int n, vector<vector<int>>& me) {
        vector<int> count(n,0);
        sort(me.begin(),me.end());
        priority_queue<P,vector<P>,greater<P>> pq;
        priority_queue<int,vector<int>,greater<int>> avail;
        for(int i=0;i<n;i++)avail.push(i);
        for(auto &it:me)
        {
            int start=it[0];
            int end=it[1];
            int duration=end-start;
            while(!pq.empty() && pq.top().first<=start)
            {
                int roomnumber=pq.top().second;
                pq.pop();
                avail.push(roomnumber);
            }
            if(!avail.empty())
            {
                int room=avail.top();
                avail.pop();
                pq.push({end,room});
                count[room]++;
            }
            else{
                int room=pq.top().second;
                long long endtime=pq.top().first;
                pq.pop();
                pq.push({endtime+duration,room});
                count[room]++;
            }

        }
        int ans=0,res=-1;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]>ans)
            {
                ans=count[i];
                res=i;
            }
        }
        return res;

    }
};