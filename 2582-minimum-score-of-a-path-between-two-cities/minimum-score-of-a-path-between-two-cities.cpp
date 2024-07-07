class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,0);
        for(int i=0;i<n+1;i++)parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBySize(int u,int v){
        int pu=findUpar(u),pv=findUpar(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            size[pv]++;
            parent[pu]=pv;
        }
        else{
            size[pu]++;
            parent[pv]=pu;
        }
        return;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n+1);
        for(auto it:roads){
            ds.unionBySize(it[1],it[0]);
        }
        int ans=INT_MAX;
        for(auto it:roads){
            if(ds.findUpar(1)==ds.findUpar(it[1]))ans=min(ans,it[2]);
        }
        return ans;
    }
};