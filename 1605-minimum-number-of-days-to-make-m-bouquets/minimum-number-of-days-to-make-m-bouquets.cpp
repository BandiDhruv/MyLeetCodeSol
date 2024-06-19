class Solution {
public:
    long long n;
    bool solve(int days,vector<int>& b, int m, int k){
        int temp=k;
        int i=0;
        // cout<<i<<" \n";
        while(m){
            // cout<<m<<" - ";
            for(;i<n;){
                // cout<<b[i]<<" ";
                if(b[i]<=days)k--;
                else k=temp;
                i++;
                if(k==0){
                    m--;
                    break;
                }
            }
            if(i==n)break;
            // cout<<endl;
            k=temp;
        }
        return m==0;
    }
    int minDays(vector<int>& b, int m, int k) {
        n=b.size();
        long long size=(long long)m*k*1ll;
        if(n<size)return -1;
        // sort(b.begin(),b.end());
        int lo=0,hi=*max_element(b.begin(),b.end()),ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            cout<<mid<<" "<<solve(mid,b,m,k)<<endl;
            if(solve(mid,b,m,k))
                ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};