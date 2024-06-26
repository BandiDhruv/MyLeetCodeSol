class LockingTree {
public:
    unordered_map<int,vector<int>> mpchild;
    unordered_map<int,int> mp;
    vector<int> parentt;
    LockingTree(vector<int>& parent) {
        parentt=parent;
        for(int i=0;i<parent.size();i++){
            mpchild[parent[i]].push_back(i);
        }    
    }
    
    bool lock(int num, int user) {
        if(mp.find(num)==mp.end()){
            mp[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(mp.find(num)!=mp.end())
        {
            if(mp[num]==user){
                mp.erase(num);
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    
    bool upgrade(int num, int user) {
        if(mp.find(num)!=mp.end())
            return false;
        int par=parentt[num];
        while(par!=-1){
            if(mp.find(par)!=mp.end())
                return false; 
            par=parentt[par];
        }
        bool isdeslocked=false;
        queue<int> q;
        q.push(num);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                for(auto it:mpchild[node]){
                    q.push(it);
                    if(mp.find(it)!=mp.end()){
                        isdeslocked=true;
                        mp.erase(it);
                    }
                }
            }
        }
        if(!isdeslocked)
            return false;
        mp[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */