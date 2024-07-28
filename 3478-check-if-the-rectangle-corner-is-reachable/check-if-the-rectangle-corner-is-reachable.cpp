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
    double dist(double x1,double y1,double x2,double y2){
        double ans=sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); 
        return ans;
    }
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n=circles.size();
        DisjointSet ds(n+3);
        map<pair<int,pair<int,int>>,int> mp;
        int cnt=0;
        mp[{0,{0,0}}]=cnt++;
        mp[{X,{Y,0}}]=cnt++;
        for(auto it:circles){
            mp[{it[0],{it[1],it[2]}}]=cnt++;
        }
        for(int i=0;i<n;i++){
            int x=circles[i][0],y=circles[i][1],r=circles[i][2];
            if(x-r<=0 || y+r>=Y)
            {
                int p=mp[{x,{y,r}}];
                int q=mp[{0,{0,0}}];
                ds.unionBySize(p,q);
            }
            if(x+r>=X || y-r<=0){
                int p=mp[{x,{y,r}}];
                int q=mp[{X,{Y,0}}];
                ds.unionBySize(p,q);
            }
        }
        for(int i=0;i<n-1;i++){
            int x1=circles[i][0],y1=circles[i][1],r1=circles[i][2];
            for(int j=i+1;j<n;j++){
                int x2=circles[j][0],y2=circles[j][1],r2=circles[j][2];
                double dis=dist((double)x1,(double)y1,(double)x2,(double)y2);
                if(dis<=double(r1+r2)){
                    int p=mp[{x1,{y1,r1}}];
                    int q=mp[{x2,{y2,r2}}];
                    ds.unionBySize(p,q);
                }
            }
        }
        int q=mp[{X,{Y,0}}];
        int p=mp[{0,{0,0}}];
        // cout<<ds.findUpar(p)<<" "<<ds.findUpar(q);
        return !(ds.findUpar(p)==ds.findUpar(q));
    }
};