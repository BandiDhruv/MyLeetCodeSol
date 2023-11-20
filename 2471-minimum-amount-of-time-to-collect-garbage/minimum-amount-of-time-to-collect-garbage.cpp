class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<garbage.size();i++)
        {
            for(auto it:garbage[i])
            {
                mp[it].push_back(i);
            }
        }
        long long ans=0;
        vector<int> pre(travel.size());
        pre[0]=travel[0];
        for(int i=1;i<travel.size();i++)
        {
            pre[i]=pre[i-1]+travel[i];
        }
        vector<int>fre(3,0);
        for(int i=0;i<garbage.size();i++)
        {
            for(int j=0;j<garbage[i].size();j++)
            {
                if(garbage[i][j]=='M')
                    fre[0]++;
                else if(garbage[i][j]=='P')
                    fre[1]++;
                else
                    fre[2]++;
            }
        }
        for(int i=0;i<3;i++)
        {
            cout<<fre[i]<<endl;
        }
        for(auto it:mp)
        {
            if(it.first=='M')
                ans+=fre[0];
            else if(it.first=='P')
                ans+=fre[1];
            else
                ans+=fre[2];
            int a=it.second[it.second.size()-1];
            if(a>0)
            ans+=pre[a-1];

            cout<<it.first<<"  ==>>  "<<ans<<endl;
        }
        return ans;
    }
};