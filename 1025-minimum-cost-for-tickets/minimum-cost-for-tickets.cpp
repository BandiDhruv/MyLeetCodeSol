class Solution {
public:
    int t[400];
    int solve(vector<int>& days, vector<int>& costs,int i){
        if(i>=days.size())return 0;
        if(t[i]!=-1)return t[i];
        int op1=0,op2=0,op3=0;
        int curr=days[i];
        op1=costs[0]+solve(days,costs,lower_bound(days.begin(),days.end(),days[i]+1)-days.begin());
        op2=costs[1]+solve(days,costs,lower_bound(days.begin(),days.end(),days[i]+7)-days.begin());
        op3=costs[2]+solve(days,costs,lower_bound(days.begin(),days.end(),days[i]+30)-days.begin());
        return t[i]= min(op1,min(op2,op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(days,costs,0);
    }
};