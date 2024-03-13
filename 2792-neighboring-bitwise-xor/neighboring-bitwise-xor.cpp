class Solution {
public:
    int n;
    bool doesValidArrayExist(vector<int>& derived) {
        // n=derived.size();
        // vector<int> ans(n);
        if(n==1)return derived[0]==0;
        // if(n==2){
        //     int sum=derived[0]+derived[1];
        //     if(sum==1)return false;
        //     return true;
        // }
        // ans[0]=0;
        // // ans[n-1]=1;
        // bool f=true;
        // for(int i=1;i<n-1;i++)
        // {
        //     if(derived[i]==1)
        //         ans[i]=!ans[i-1];
        //     else ans[i]=ans[i-1];
        // }
        // if(derived[n-1]==1)
        // {
        //     ans[n-1]!=ans[0];
        // }
        // else ans[n-1]=ans[0];
        // for(int i=0;i<n-1;i++)
        // {
        //     if(derived[i]!=ans[i]^ans[i+1]){f=false;break;}
        // }
        // if(f)return true;
        //  ans[0]=1;
        // // ans[n-1]=1;
        // f=true;
        // for(int i=1;i<n-1;i++)
        // {
        //     if(derived[i]==1)
        //         ans[i]=!ans[i-1];
        //     else ans[i]=ans[i-1];
        // }
        // if(derived[n-1]==1)
        // {
        //     ans[n-1]!=ans[0];
        // }
        // else ans[n-1]=ans[0];
        // for(int i=0;i<n-1;i++)
        // {
        //     if(derived[i]!=ans[i]^ans[i+1]){f=false;break;}
        // }
        // return f;
        int sum=0;
        for(auto it:derived)sum+=it;
        if(sum%2==0)return true;
        return false;
    }
};