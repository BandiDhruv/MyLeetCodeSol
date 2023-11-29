class Solution {
public:int m=1e9+7;
    int numberOfWays(string corridor) {
        int seats=0,plants=0;
        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i]=='P')
                plants++;
            else
                seats++;
        }
        cout<<seats<<" . "<<plants<<endl;
        if(seats%2!=0)
            return 0;
        if(seats==2)
            return 1;
        if(seats==0)
            return 0;
        // return plants;
        int con=0;
        long long int ans=1;
        int prev=0;
        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i]=='S' ){
                con++;
                if(con%2!=0 && con>2)
                {
                    ans=ans*(i-prev)%m;
                }
                prev=i;
            }
        }
        return ans;
    }
};