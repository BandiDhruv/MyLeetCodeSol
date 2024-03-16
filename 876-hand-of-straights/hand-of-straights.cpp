class Solution {
public:
    typedef pair<int,int> P;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<P,vector<P>,greater<P>> pq;
        map<int,int> mp;
        if(hand.size()%groupSize!=0)return false;
        for(auto it:hand)mp[it]++;
        for(auto it:mp)
            pq.push({it.first,it.second});
        while(!pq.empty())
        {
            vector<int> temp;
            int i=0;
            while(i<groupSize)
            {
                int ele=pq.top().first;
                if(!temp.empty()){
                    if(ele!=temp.back()+1)return false;
                }
                pq.pop();
                mp[ele]--;
                temp.push_back(ele);
                i++;
            }
            for(auto it:temp)if(mp[it]>0)pq.push({it,mp[it]});
        }
        return true;
    }
};