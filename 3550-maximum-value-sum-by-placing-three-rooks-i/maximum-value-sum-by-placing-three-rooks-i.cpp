class Solution {
public:
    long long dp[102][102][102][4];
    long long solve(vector<vector<pair<long long,long long>>> &vp,int i,int p1,int p2,int cnt){
        if(cnt==3) 
            return 0;
        if(i>=vp.size())
            return -3e9;
        if(dp[i][p1+1][p2+1][cnt]!=-1)
            return dp[i][p1+1][p2+1][cnt];
        long long ans=-3e9;
        ans=max(ans,solve(vp,i+1,p1,p2,cnt));
        if(p1==-1){
            for(int k=0;k<vp[i].size();k++){
                ans=max(ans,vp[i][k].first+solve(vp,i+1,vp[i][k].second,p2,cnt+1));
            }
        }
        else if(p2==-1){
            for(int k=0;k<vp[i].size();k++){
                if(vp[i][k].second!=p1)
                    ans=max(ans,vp[i][k].first+solve(vp,i+1,p1,vp[i][k].second,cnt+1));
            }
        }
        else{
            for(int k=0;k<vp[i].size();k++){
                if(vp[i][k].second!=p1 && vp[i][k].second!=p2)
                    ans=max(ans,vp[i][k].first+solve(vp,i+1,p1,p2,cnt+1));
            }
        }
        return dp[i][p1+1][p2+1][cnt]=ans;
    }
    long long maximumValueSum(vector<vector<int>>& board) {
        long long ans=0;
        vector<vector<pair<long long,long long>>> a(board.size());
        for(int i=0;i<board.size();i++){
            priority_queue<pair<long long,long long>> pq;
            for(int j=0;j<board[i].size();j++){
                pq.push({board[i][j],j});
            }
            int t=3;
            while(t>0){
                a[i].push_back(pq.top());
                pq.pop();
                t--;
            }
        }
        memset(dp,-1,sizeof(dp));
        for(auto it:a)
        {
            for(auto i:it){
                cout<<i.first<<" "<<i.second<<" | ";
            }
            cout<<endl;
        }
        return solve(a,0,-1,-1,0);
    }
};