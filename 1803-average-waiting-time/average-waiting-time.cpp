class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n=customers.size();
        double t=customers[0][0]+customers[0][1];
        double ans=customers[0][1];
        for(int i=1;i<n;i++){
            cout<<t<<"  "<<ans<<" \n";
            if(t>customers[i][0]){
                t+=customers[i][1];
                ans+=(t-customers[i][0]);
            }
            else {
                ans+=customers[i][1];
                t=customers[i][0]+customers[i][1];
            }
        }
        cout<<ans<<" "<<n<<" \n";
        return ans/n;
    }
};