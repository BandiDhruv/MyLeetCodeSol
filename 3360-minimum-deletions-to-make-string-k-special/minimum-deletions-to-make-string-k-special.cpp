class Solution {
public:
    int minimumDeletions(string w, int k) {
        vector<int> freq(26,0);
        int n=w.size();
        for(int i=0;i<n;i++){
            freq[w[i]-'a']++;
        }
        sort(begin(freq),end(freq));
        int ans=INT_MAX;
        for(int i=0;i<freq.size();i++)
        {
            int cnt=0;
            for(int j=0;j<freq.size();j++){
                if(j<i)cnt+=freq[j];
                else if(freq[j]<=freq[i]+k)continue;
                else cnt+=(freq[j]-freq[i]-k);
            }
            ans=min(ans,cnt);

        } 
        return ans;
        
    }

};