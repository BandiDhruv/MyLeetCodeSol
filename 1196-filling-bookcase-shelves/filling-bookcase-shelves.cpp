class Solution {
public:
    int SW;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int sw,int i,int maxi){
        int nmaxi=max(maxi,books[i][1]);
        if(t[i][sw]!=-1)return t[i][sw];
        if(i==books.size()-1){
            if(sw-books[i][0]>=0)return nmaxi;
            return maxi+books[i][1];
        }
        int notplace=maxi+solve(books,SW-books[i][0],i+1,books[i][1]);
        if(sw-books[i][0]>=0)
        {
            int place=solve(books,sw-books[i][0],i+1,nmaxi);
            return t[i][sw]=min(place,notplace);
        }
        return t[i][sw]=notplace;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        SW=shelfWidth;
        memset(t,-1,sizeof(t));
        return solve(books,shelfWidth,0,0);
    }
};