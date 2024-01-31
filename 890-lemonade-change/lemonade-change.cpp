class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ans=0;
        int f=0,t=0,tw=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)f++;
            if(bills[i]==10)
            {
                t++;
                if(f<=0){return false;}
                f--;
            }
            if(bills[i]==20)
            {
                tw++;
                if(t<=0 && f<3)return false;
                if(f<1)return false;
                if(t>0)
                {
                    t--;
                    f--;
                }
                else{
                    f-=3;
                }
            }
        }
        return true;
    }
};