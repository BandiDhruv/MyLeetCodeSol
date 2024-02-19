class Solution {
public:
    int n;
    // int solve(vector<int>& heights,int idx, int b, int l)
    // {
    //     if(idx==n-1)return 0;
    //     if(heights[idx]>=heights[idx+1]) return =1+solve(heights,idx+1,b,l);
    //     else{
    //         int bb=0,bl=0,diff=heights[idx+1]-heights[idx];
    //         if(b>=diff) bb=1+solve(heights,idx+1,b-diff,l);
    //         if(l>0) bl=1+solve(heights,idx+1,b,l-1);
    //         return max(bl,bb);
    //     }
    //     return 0;
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n=heights.size();
        priority_queue<int> pq;
        int i=0;
        for(;i<n-1;i++)
        {
            if(heights[i+1]<=heights[i]) continue;
            int diff=heights[i+1]-heights[i];
            if(bricks>=diff)
            {
                pq.push(diff);
                bricks-=diff;
            }
            else if(ladders>0)
            {
                if(!pq.empty())
                {
                    int max_bricks_past=pq.top();
                    if(max_bricks_past>=diff){
                        bricks+=max_bricks_past;
                        pq.pop();
                        bricks-=diff;
                        pq.push(diff);
                        ladders--;
                    }
                    else ladders--;
                }
                else ladders--;
            }
            else break;
        }
        return i;

    }
};