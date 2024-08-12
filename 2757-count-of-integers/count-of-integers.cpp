class Solution {
public:
    typedef long long ll;
    ll mod=(int)1e9+7;
    string conv(string a){
        int i=a.size()-1;
        while(a[i]=='0' && i>=0){
            a[i]='9';
            i--;
        }
        if(i==0)
            return "0";
        int p=a[i]-'0'-1;
        a[i]=char(p+'0');
        return a;
    }
    ll dp[220][24][2];
    int solve(string nums,int minSum,int maxSum,ll currSum,int i,bool f){
        if(i==nums.size()){
            if(currSum<=maxSum && currSum>=minSum)
                return 1;
            return 0; 
        }
        if(dp[currSum][i][f]!=-1)
            return dp[currSum][i][f];
        ll ans=0;
        if(f){
            for(char x='0';x<='9';x++){
                int num=x-'0';
                ans+=solve(nums,minSum,maxSum,currSum+num,i+1,true);
                ans%=mod;
            }
        }else{
            for(char x='0';x<=nums[i];x++){
                int num=x-'0';
                ans+=solve(nums,minSum,maxSum,currSum+num,i+1,(x!=nums[i]));
                ans%=mod;
            }
        }
        return dp[currSum][i][f]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        string ans=conv(num1);
        cout<<ans<<endl;
        memset(dp,-1,sizeof(dp));
        ll t2=solve(num2,min_sum,max_sum,0,0,false);
        memset(dp,-1,sizeof(dp));
        ll t1=solve(ans,min_sum,max_sum,0,0,false);
        cout<<t1<<" "<<t2<<endl;
        if(num1.size()==1 && num1[0]=='0'){
            return t2;
        }
        return (t2 - t1 + mod) % mod;
    }
};