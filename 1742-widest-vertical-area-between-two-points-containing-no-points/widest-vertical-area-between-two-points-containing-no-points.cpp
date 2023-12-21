class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        unordered_map<int,int> st;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            st[points[i][0]]++;
        }
        int ans=INT_MIN;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size()-1;i++)
        {
            // int f=0;
            // int l=points[i][0]+1,r=points[i+1][0];
             ans=max(ans,points[i+1][0]-points[i][0]);
        }
        return ans;
    }
};