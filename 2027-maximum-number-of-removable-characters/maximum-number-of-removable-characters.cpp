class Solution {
public:
    bool solve(int mid,string s,string p,vector<int>&r){
        int i=0,j=0,k=0;
        vector<int> vis(s.size(),1);
        for(int i=0;i<=mid;i++)vis[r[i]]=0;
        while(i<s.size() && k<p.size()){
            if(s[i]==p[k] && vis[i])k++;
            i++;
        }
        return k==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& r) {
        int i=0,j=r.size()-1;
        while(i<=j){
            int mid=(i+j)>>1;
            if(solve(mid,s,p,r))
                i=mid+1;
            else j=mid-1;
        }
        return i;
    }
};