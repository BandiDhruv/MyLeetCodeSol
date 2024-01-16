class RandomizedSet {
public:
        set<int> st;
        vector<int> ans;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end())
        {
            ans.push_back(val);
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val)==st.end())
        {
            return false;
        }else {
            auto it = find(ans.begin(), ans.end(),val);
            ans.erase(it);
            st.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int n=st.size();
        int range=n-1-0+1;
        int idx=rand()%range+0;
        return ans[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */