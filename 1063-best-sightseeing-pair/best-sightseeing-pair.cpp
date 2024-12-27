class Solution {
public:
    int t[60000][4];
    int solve(vector<int>&v,int i,int f){
        if(i>=v.size()){
            if(f==2)
                return 0;
            return -1e7;
        }
        if(t[i][f]!=-1)
            return t[i][f];
        int op1=0,op2=0;
        if(f==0){
            op1 = v[i] + i + solve(v,i+1,1);
            op2 = solve(v,i+1,f);  
        }
        else if(f==1){
            op1 = v[i] -i+solve(v,i+1,f+1);
            op2 = solve(v,i+1,f); 
        }
        return t[i][f]=max(op1,op2);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(t,-1,sizeof(t));
        return solve(values,0,0);    
    }
};