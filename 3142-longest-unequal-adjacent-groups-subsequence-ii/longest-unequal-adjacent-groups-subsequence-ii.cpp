class Solution {
public:
    bool hamming(string a,string b){
        if(a.size()!=b.size())
            return false;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i] && cnt==0)cnt++;
            else if(a[i]!=b[i])return false;
        }
        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;   
        int n=words.size(); 
        vector<int> dp(n,0),hashing(n);
        int idx=0,res=-1;
        for(int i=0;i<n;i++){
            hashing[i]=i;
            for(int j=0;j<i;j++){
                if(dp[j]+1>dp[i] 
                && hamming(words[i],words[j])
                && groups[i]!=groups[j])
                {
                    hashing[i]=j;
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>res){
                res=dp[i];
                idx=i;
            }
        }
        ans.push_back(words[idx]);
        // for(auto it:hashing){
        //     cout<<it<<" ";
        // }
        while(idx!=hashing[idx]){
            idx=hashing[idx];
            ans.push_back(words[idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};