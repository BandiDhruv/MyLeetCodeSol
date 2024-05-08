class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> mp;
        for(int i=0;i<score.size();i++){
            mp.push_back({score[i],i});
        }
        sort(mp.rbegin(),mp.rend());
        vector<string> ans(score.size());
        int cnt=0;
        for(auto it:mp){
            
            cnt++;
            if(cnt==1)ans[it.second]="Gold Medal";
            else if(cnt==2)ans[it.second]="Silver Medal";
            else if(cnt==3)ans[it.second]="Bronze Medal";   
            else ans[it.second]=to_string(cnt);
        }
        return ans;
    }
};