class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    bool connected(int u,int v){
        return findUPar(u)==findUPar(v);
    }
    void reset(int u){
        parent[u]=u;
        rank[u]=0;
    }

};

class Solution {
public:
    static bool cmp(const vector<int> &a,const vector<int> &b)
    {
        return a.back()<b.back();
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSet ds(n+1);
        sort(meetings.begin(), meetings.end(), cmp);
        ds.unionByRank(0,firstPerson);
        int i=0;
        while(i<meetings.size()){
            vector<int> temp;
            int time=meetings[i][2];
            while(i<meetings.size() && meetings[i][2]==time){
                ds.unionByRank(meetings[i][0],meetings[i][1]);
                temp.push_back(meetings[i][0]);
                temp.push_back(meetings[i][1]);
                i++;
            };
            for(auto &it:temp)
            {
                if(!ds.connected(0,it))ds.reset(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ds.connected(0,i))ans.push_back(i);
        }
        return ans;
    }

};