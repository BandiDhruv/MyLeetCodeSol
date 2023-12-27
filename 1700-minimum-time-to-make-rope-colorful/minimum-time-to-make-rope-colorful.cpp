class Solution {
public:
    // int solve(string colors,vector<int>&needTime,int idx)
    // {
    //     if(idx>=colors.size()) return 0;
    //     int take=0,nottake=0;
    //     cout<<idx<<"  ";

    //     if(!vis[idx] && !vis[idx-1])
    //     {
    //         if(colors[idx] == colors[idx-1])
    //         {
    //             if(needTime[idx]<needTime[idx-1])
    //                 vis[idx]=true;
    //             else vis[idx-1]=true;    
    //             return min(needTime[idx],needTime[idx-1])+solve(colors,needTime,idx+1);
    //         }
    //     }
        
    //     return solve(colors,needTime,idx+1);
    // }

    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int prev=0;
        for(int i=0;i<colors.size();i++)
        {
            if(i>0 && colors[i]!=colors[i-1])
            {
                prev=0;
            }
            ans+=min(prev,neededTime[i]);
            prev=max(prev,neededTime[i]);
        }
        return ans;
    }
};