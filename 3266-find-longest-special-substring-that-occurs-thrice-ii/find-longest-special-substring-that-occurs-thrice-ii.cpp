class Solution {
public:
    bool solve(int mid,string s){
        int left=0;
        vector<int>f(26,0);
        int cnt=0;
        unordered_map<int,int> mp;
        for(int right=0;right<s.size();right++){
            f[s[right]-'a']++;
            while(right-left+1>mid && left<=right){
                f[s[left]-'a']--;
                left++;
            }
            if(right-left+1==mid){
                int temp=-1;
                int counts=0;
                for(int i=0;i<26;i++){
                    if(f[i]>0){temp=i;counts++;}
                }
                if(temp!=-1 && counts==1){
                    mp[temp]++;
                }
            }
        }
        for(auto it:mp)
            if(it.second>=3)return true;
        return false;
    }
    int maximumLength(string s) {
        int lo=1,hi=s.size();
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(solve(mid,s)){
                cout<<mid<<endl;
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};