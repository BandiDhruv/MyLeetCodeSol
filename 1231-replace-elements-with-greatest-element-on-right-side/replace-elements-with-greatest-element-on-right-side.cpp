class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        ans[n-1]=-1;
        vector<int>suf(n);
        suf[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=max(arr[i+1],suf[i+1]);
            cout<<arr[i];
            suf[i]=max(arr[i],suf[i+1]);
        }
        return ans;
        
    }
};