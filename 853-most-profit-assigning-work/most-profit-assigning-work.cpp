class Solution {
public:
    bool static cmp(const pair<int,int>&a,const int &v){
        return a.first<=v;
    }
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int ans=0;
        vector<pair<int,int>> vp;
        int n=d.size();
        for(int i=0;i<n;i++){
            vp.push_back({d[i],p[i]});
        }
        vector<int> maxTillI(n);
        sort(begin(vp),end(vp));
        maxTillI[0]=vp[0].second;
        for(int i=1;i<n;i++){
            maxTillI[i]=max(maxTillI[i-1],vp[i].second);
        }
        for(auto it:w){
            auto idx=lower_bound(vp.begin(),vp.end(),it,cmp)-vp.begin();
            // if(idx==n)continue;
            if(vp[idx].first==it )ans+=maxTillI[idx];
            else if(idx>0)ans+=maxTillI[idx-1];
            // cout<<it<<" -> "<<vp[idx].first<<endl;
        }
        return ans;
    }
};