class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,int>> pq;//{freq,timestamp}
        queue<pair<int,int>> q;//{freq,time}
        vector<int> freq(26,0);
        for(auto it:tasks)
            freq[it-'A']++;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0){
                pq.push({freq[i],0});
            }   
        }
        int ans=0;
        int time=0;
        while(!pq.empty() || !q.empty())
        {
            while(!q.empty() && (time-q.front().second>n))
            {
                pq.push(q.front());
                q.pop();
            }
            if(!pq.empty() && pq.top().first>=1)
            {
                int fre=pq.top().first;
                int timestamp=pq.top().second;
                fre--;
                timestamp=time;
                if(fre!=0)q.push({fre,timestamp});
                pq.pop();
            }
            time++;
        }
        return max(time,(int)tasks.size());
    }
};