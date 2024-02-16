class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto &i:arr)mp[i]++;
        if(arr.size()==1 && k==1)return 0;
        else if(arr.size()==1 && k==0)return 1;
        deque<int> f;
        for(auto &i:mp)
        {
            f.push_back(i.second);
        }
        sort(f.begin(),f.end());
        while(k>=0)
        {
            if(f.front()>k)return f.size();
            // cout<<mp.begin()->second;
            if(f.size()==0)break;
            k-=f.front();
            f.pop_front();
        }
        return 0;
    }
};