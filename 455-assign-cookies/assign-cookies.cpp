class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {//
        int c=0,j=0 ;
        if(s.size()==0)
            return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i=0;i<g.size();i++)
        {
            while(j<s.size())
            {
                if(s[j]>=g[i])
                {
                    c++;
                j++;
                    break;
                
                }
                else
                    j++;
                
            }
            
        }
        return c;
        
    }
};