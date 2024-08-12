class Solution {
public:
    int dp[11][11][21][11][2][2];
    int solve(int k,int cntO,int cntE,int num,string limit,int i,bool f,bool isF){
        if(i==limit.size()){
            if(cntO == cntE && !isF){
                if(num==0)
                    return 1;
            }
            return 0;
        }
        if(dp[cntO][cntE][num][i][f][isF]!=-1)return dp[cntO][cntE][num][i][f][isF];
        int ans=0;
        if(f){
            for(char ch='0';ch<='9';ch++){
                int no=ch-'0';
                if(isF){
                    if(no>0){
                        ans+=solve(k,cntO+(no%2!=0),cntE+(no%2==0),((num*10)+no)%k,limit,i+1,true,false);
                    }else{
                        ans+=solve(k,cntO,cntE,((num*10)+no)%k,limit,i+1,true,true);
                    }
                }
                else {
                    ans+=solve(k,cntO+(no%2!=0),cntE+(no%2==0),((num*10)+no)%k,limit,i+1,true,false);
                }
            }  
        }
        else{
            for(char ch='0';ch<=limit[i];ch++){
                int no=ch-'0';
                if(isF){
                    if(no>0){
                        ans+=solve(k,cntO+(no%2!=0),cntE+(no%2==0),((num*10)+no)%k,limit,i+1,(ch==limit[i]?false:true),false);
                    }else{
                        ans+=solve(k,cntO,cntE,((num*10)+no)%k,limit,i+1,(ch==limit[i]?false:true),true);
                    }
                }
                else {
                    ans+=solve(k,cntO+(no%2!=0),cntE+(no%2==0),((num*10)+no)%k,limit,i+1,(ch==limit[i]?false:true),false);
                }
            }
        }
        return dp[cntO][cntE][num][i][f][isF]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string t1=to_string(low-1),t2=to_string(high);
        // cout<<t1<<" "<<t2<<endl;
        memset(dp,-1,sizeof(dp));
        int temp1= solve(k,0,0,0,t2,0,false,true);
        memset(dp,-1,sizeof(dp));
        int temp2= solve(k,0,0,0,t1,0,false,true);
        // cout<<temp2<<" "<<temp1<<endl;
        if(low==0)
            return temp1;
        return temp1-temp2;
    }
};