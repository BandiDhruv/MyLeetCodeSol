class TimeMap {
public:
    bool static cmp(const pair<int,string>&a,const int &v){
        return a.first<=v;
    }
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int idx=lower_bound(mp[key].begin(),mp[key].end(),timestamp,cmp)-mp[key].begin();
        if(idx>0)return mp[key][idx-1].second;
        else return "";

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */