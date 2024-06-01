class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> ans;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end()){
            mp[val]++;
            ans.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            mp.erase(val);
            ans.erase(find(ans.begin(),ans.end(),val));
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int size=ans.size();
        return ans[rand()%size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */