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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsa(n),dsb(n);
        sort(edges.rbegin(),edges.rend());
        int idx=0;
        int ans=0;
        for(auto it:edges){
            if(it[0]!=3)break;
            idx++;
            int u=it[1],v=it[2];
            if(dsa.findUpar(u)!=dsa.findUpar(v)){
                dsa.unionBySize(u,v);
                dsb.unionBySize(u,v);
                ans++;
            }
        }   
        int cnt=0;
        for(int j=idx;j<edges.size();j++){
            int type=edges[j][0],u=edges[j][1],v=edges[j][2];
            if(type==1){
                if(dsa.findUpar(u)!=dsa.findUpar(v)){
                    ans++;
                    dsa.unionBySize(u,v);
                }
            }
            if(type==2){
                if(dsb.findUpar(u)!=dsb.findUpar(v)){
                    ans++;
                    dsb.unionBySize(u,v);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dsa.findUpar(i)!=dsa.findUpar(1))return -1;
            if(dsb.findUpar(i)!=dsb.findUpar(1))return -1;
        }
        return edges.size()-ans;
    }
};