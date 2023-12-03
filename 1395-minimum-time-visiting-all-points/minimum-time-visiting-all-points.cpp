class Solution {
public:
    // int dis(int x1,int x2,int y1,int y2)
    // {
    //     int ans=floor(sqrt(((x1-x2)*(x1-x2)) + ((y1 -y2)*(y1-y2))));
    //     return ans;
    // }
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans=0;
        for(int i=0;i<p.size()-1;i++)
        {
            // ans+=dis(points[i][0],points[i+1][0],points[i][1],points[i+1][1]);
            // cout<<dis(points[i][0],points[i+1][0],points[i][1],points[i+1][1])<<"  "<<i<<endl;
            ans+=max(abs(p[i][1]-p[i+1][1]),abs(p[i][0]-p[i+1][0]));
        }
        return ans;
    }
};