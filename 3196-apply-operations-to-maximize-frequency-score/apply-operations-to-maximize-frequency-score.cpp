class Solution {
public:
    typedef long long ll;
    bool solve(int len,vector<int>&nums,vector<ll> &pre,ll k)
    {
        int i=0;
        int j=len-1;

        while(j<nums.size())
        {
            ll operationleft,operationright;
            ll mid=(j+i)/2;
            ll leftlen=mid-i;
            if(mid==0)operationleft=0;
            else
            {
                ll leftsum=pre[mid-1]-((i>0)?pre[i-1]:0);
                ll leftsumcurr=leftlen*nums[mid];
                operationleft=abs(leftsum-leftsumcurr);
            }
            ll rightlen=j-mid;
            ll rightsum=pre[j]-pre[mid];
            ll rightsumcurr=rightlen*nums[mid];
            operationright=abs(rightsum-rightsumcurr);
            if(operationleft + operationright <= k) return true;
            
            i++;
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int l=1,r=n;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(solve(mid,nums,pre,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};