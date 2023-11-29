class Solution {
public:
// static bool cmp(const pair<int,int>&a,const pair<int,int>&b)
// {
//     return a.second<b.second;
// }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // unordered_map<int,vector<int,int>> mp;
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    if(i!=0){
                        if(matrix[i-1][j]!=0)
                        {
                            matrix[i][j]=matrix[i-1][j]+1;
                        }
                    }
                }
            }
            vector<int> heights=matrix[i];
            sort(heights.rbegin(),heights.rend());
            for(int i=0;i<heights.size();i++)
            {
                int base=i+1;
                int height=heights[i];
                int area=base*height;
                ans=max(ans,area);
            }
        }
        return ans;
        // vector<int> dec;
        // for(int i=0;i<matrix[0].size();i++)
        // {
        //     dec.push_back(matrix[matrix.size()-1][i]);
        // }
        // sort(dec.rbegin(),dec.rend());
        // for(int i=0;i<matrix[i].size();i++)
        // {
        //     mp[matrix[matrix.size()-1][i]].push
        // }
        // int c1=0,c0=0;
        // int c=0;
        // for(auto it:mp)
        // {
        //     sort(it.second.begin(),it.second.end(),cmp);
        //     for(auto i:it.second)
        //     {
        //         cout<<it.first<<"->"<<i.first<<","<<i.second<<endl;
        //     }
        //     cout<<endl;
        // }

        // return 0;
    }
};