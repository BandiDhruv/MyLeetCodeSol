class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& me) {
        vector<int> count(n,0);
        vector<long long> lastAvailable(n,0);
        sort(me.begin(),me.end());
        for(auto &it:me)
        {
            int start=it[0];
            int end=it[1];
            int duration=end-start;
            bool found=0;
            long long earlyroomend=LLONG_MAX;
            int earlyroomidx=0;
            for(int room=0;room<n;room++)
            {
                if(lastAvailable[room] <= start)
                {
                    count[room]++;
                    lastAvailable[room]=end;
                    found=true;
                    break;
                }
                if(lastAvailable[room]<earlyroomend)
                {
                    earlyroomend=lastAvailable[room];
                    earlyroomidx=room;
                }
            }
            if(!found)
            {
                lastAvailable[earlyroomidx]+=duration;
                count[earlyroomidx]++;
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