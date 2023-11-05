class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi=arr[0];
        queue<int> q;
        for(int i=1;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i]);
            q.push(arr[i]);
        }
        int curr=arr[0];
        int winstreak=0;
        while(!q.empty())
        {
            int opponent=q.front();
            q.pop();
            if(curr > opponent)
            {
                winstreak++;
                q.push(opponent);
            }
            else
            {
                q.push(curr);
                curr=opponent;
                winstreak=1;
            }
            if(winstreak==k || curr==maxi)
                return curr;
        }
        return -1;
    }
};