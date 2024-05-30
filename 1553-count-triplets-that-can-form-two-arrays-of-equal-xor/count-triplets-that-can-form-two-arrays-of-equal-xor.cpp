class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>pre(n);
        int ans=0;
        pre[0]=arr[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]^arr[i];

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    int a=(i==0)?pre[j-1]:pre[j-1]^pre[i-1];
                    int b=pre[k]^pre[j-1];
                    if(a==b)ans++;
                }
            }
        }
        return ans;
    }
};