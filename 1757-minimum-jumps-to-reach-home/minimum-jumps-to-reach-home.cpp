class Solution {
public:
    map<int,int>mp;

    int minimumJumps(vector<int>&forbidden,int a, int b, int x) {
        for(auto it:forbidden)
            mp[it]++;
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--){
                auto it=q.front();
                q.pop();
                int back=it.second;
                int i=it.first;
                if(i==x)
                    return ans;
                if(back==0 && i>=b && !mp.count(i-b)){
                    q.push({i-b,1});
                    mp[i-b]=1;
                }
                if(!mp.count(i+a) && i+a<=6000){
                    q.push({i+a,0});
                    mp[i+a]=1;
                }
            }
            ans++;
        }
        return -1;
    }
};