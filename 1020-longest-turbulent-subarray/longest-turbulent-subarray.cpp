class Solution {
public:

    int solve(vector<int>&arr,int i,int sign){
        if(i>=arr.size()-1)return 0;
        int cnt=0;
        if(sign==0){
            if(arr[i]>arr[i+1]){
                cnt=1+solve(arr,i+1,1-sign);
            }
        }
        if(sign==1){
            if(arr[i]<arr[i+1]){
                cnt=1+solve(arr,i+1,1-sign);
            }
        }
        return cnt;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,1+max(solve(arr,i,0),solve(arr,i,1)));
        }
        return ans;
    }
};