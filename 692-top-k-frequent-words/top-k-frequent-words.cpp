class Solution {
public:
    bool static cmp(pair<string,int> &a, pair<string,int> &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        // priority_queue<pair<int,string>> pq;
        unordered_map<string,int> mp;
        for(auto &it:words)
        {
            mp[it]++;
        }
        vector<pair<string,int>> vp(mp.begin(),mp.end());
        sort(vp.begin(),vp.end(),cmp);        
        // for(auto &it:vp)
        // {
        //     if(k==0)break;
        //     k--;
        //     pq.push({it.second,it.first});
        // }
        for(auto it:vp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        // for(auto it:pq){
        //     cout<<it<<endl;
        // }
        vector<string> ans;
        // while(!pq.empty())
        // {
        //     auto &a=pq.top();
        //     pq.pop();
        //     ans.push_back(a.second);
        // }
        int i=0;
        while(k--)
        {
            ans.push_back(vp[i++].first);
        }
        return ans;
    }
};