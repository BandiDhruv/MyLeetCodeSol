class LRUCache {
public:
    list<int> dll;
    int n;
    map<int,pair<list<int>::iterator,int>> mp;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void solve(int key)
    {
        auto add=mp[key].first;
        dll.erase(add);
        dll.push_front(key);    
        mp[key].first=dll.begin();
        return ;
    }

    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        solve(key);
        return mp[key].second;

    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            solve(key);
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            int it=dll.back();
            dll.pop_back();
            mp.erase(it);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */