class DisjointSet {
public:
    vector<int> size,parent;
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize( n + 1);
        for(int i=0;i<=n;i++){
            size[i] = 1;
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);
        if(ult_u == ult_v){
            return;
        }
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
    
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        DisjointSet ds(n);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())continue;
            mp[nums[i]]=i;
            if(mp.find(nums[i]-1)!=mp.end())ds.UnionBySize(i,mp[nums[i]-1]);
            if(mp.find(nums[i]+1)!=mp.end())ds.UnionBySize(i,mp[nums[i]+1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==ds.findUPar(i))ans=max(ans,ds.size[i]);
        }
        return ans==INT_MIN?0:ans;
    }
};