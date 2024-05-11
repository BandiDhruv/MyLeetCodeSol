class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,vector<int>>> vp;
        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                float t=float(arr[i])/float(arr[j]);
                vp.push_back({t,{arr[i],arr[j]}});
            }
        }
        sort(vp.begin(),vp.end());
        // 3n-(1+2+3)
        // n*(n-1)
        // n=4,n-1 + n-2 + n-3  
        // for(auto it:vp){
        //     cout<<it.first;
        //     for(auto i:it.second)cout<<i<<" ";
        //     cout<<endl;
        // }
        return vp[k-1].second;
    }
};