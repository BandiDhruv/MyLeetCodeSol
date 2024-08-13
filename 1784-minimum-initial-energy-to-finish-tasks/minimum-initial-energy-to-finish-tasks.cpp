class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<pair<int,int>> vp;
        int n=tasks.size();
        for(auto it:tasks){
            vp.push_back({it[1],it[0]});
        }
        sort(vp.begin(),vp.end(),[](pair<int,int>&a,pair<int,int>&b){
            return (a.first-a.second)>(b.first-b.second);
        });
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            int min=vp[i].first;
            int act=vp[i].second;
            cout<<curr<<" "<<min<<" "<<act<<" "<<ans<<endl;
            if(curr<min){
                int req=min-curr;
                curr=min;
                ans+=req;
            }
            curr-=act;
        }
        return ans;
    }
};