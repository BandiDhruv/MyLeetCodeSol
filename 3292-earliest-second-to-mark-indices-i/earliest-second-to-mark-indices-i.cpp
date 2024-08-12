class Solution {
public:
    bool solve(int mid,vector<int>&nums,vector<int> changeIndices){
        long long  n=nums.size(),m=changeIndices.size();
        vector<long long > lastIndices(n+1,-1);
        for(int i=mid-1;i>=0;i--){
            if(lastIndices[changeIndices[i]]==-1)
                lastIndices[changeIndices[i]]=i+1;
        }
        for(int i=1;i<lastIndices.size();i++)if(lastIndices[i]==-1)return false;
        long long cnt=0;
        vector<pair<long long ,long long >> vp;
        for(int i=1;i<=n;i++)vp.push_back({lastIndices[i],i});
        sort(vp.begin(),vp.end());
        for(int i=0;i<vp.size();i++){
            int lastIndex=vp[i].first;
            int index=vp[i].second;
            int needed=nums[index-1];
            long long  available=lastIndex - 1 - cnt;
            if(available>=needed)
                cnt+=needed+1;
            else return false;
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n=nums.size(),m=changeIndices.size();
        long long cnt=0,ans=-1;
        for(int i=0;i<n;i++)cnt+=nums[i]+1;
        if(cnt>m)return -1;
        int lo=cnt,high=m;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            if(solve(mid,nums,changeIndices)){
                ans=mid;
                high=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};