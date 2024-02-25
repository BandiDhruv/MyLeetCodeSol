class Solution {
public:
    int n,m;
    bool isPossible(int mid,vector<int>& nums, vector<int>& change)
    {
        unordered_map<int,int> last;
        for(int i=0;i<mid;i++){
            last[change[i]-1]=i;
        }
        if(last.size()!=n)return false;
        int operations=0,marked=0;
        for(int i=0;i<mid;i++)
        {
            if(i==last[change[i]-1])
            {
                if(operations>=nums[change[i]-1])
                {
                    operations-=nums[change[i]-1];
                    marked++;
                }
                else return false;
            }
            else operations++;
        }
        return marked==n;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& change) {
        n=nums.size();
        m=change.size();
        int lo=0,hi=m;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isPossible(mid,nums,change))
            {
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        if(ans==-1 || ans==m+1)return -1;
        return ans;

    }
};