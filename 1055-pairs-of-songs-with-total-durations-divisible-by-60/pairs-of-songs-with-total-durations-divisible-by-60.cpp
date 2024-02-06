class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> freq(60,0);
        for(int i=0;i<time.size();i++)
        {
            freq[time[i]%60]++;
        }
        long long ans=1ll*freq[0]*(freq[0]-1)/2;
        ans+=freq[30]*(freq[30]-1)/2;
        for(int i=1;i<30;i++)
        {
            if(freq[i]>0 && freq[60-i]>0)
            {
                long long tot=freq[i]*freq[60-i];
                ans+=tot;
            }
        }
        return ans;
    }
};