class Solution {
public:
    bool static cmp(pair<int, int> const& a, pair<int, int> const& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    
    typedef pair<int,int> P;
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<P> vp;
        for(int i=0;i<profits.size();i++){
            vp.push_back({capital[i],profits[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        for(auto it:vp)cout<<it.first<<" "<<it.second<<endl;

        int i=0;
        while(k--){
            while(i<vp.size() && w>=vp[i].first){
                pq.push(vp[i].second);
                i++;
            }
            if(pq.empty())break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};