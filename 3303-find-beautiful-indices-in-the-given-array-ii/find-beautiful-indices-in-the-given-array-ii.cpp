class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=s.size();
        int asize=a.size();
        int bsize=b.size();
        vector<int> alps(asize),blps(bsize);
        alps[0]=0;
        blps[0]=0;
        vector<int>astore,bstore;
        int alen=0;
        int i=1;
        while(i<asize){
            if(a[i]==a[alen])
            {
                alen++;
                alps[i]=alen;
                i++;
            }
            else{
                if(alen!=0)
                {
                    alen=alps[alen-1];
                }
                else{
                    alps[i]=0;
                    i++;
                }
            }
        }
        i=1;
        int blen=0;
        while(i<bsize)
        {
            if(b[i]==b[blen])
            {
                blen++;
                blps[i]=blen;
                i++;
            }
            else{
                if(blen!=0){
                    blen=blps[blen-1];
                }
                else{
                    blps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        int j=0;
        while(i<n)
        {
            if(s[i]==a[j])
            {
                i++;
                j++;
            }
            if(j==asize)
            {
                astore.push_back(i-j);
                j=alps[j-1];
            }
            else if(s[i]!=a[j])
            {
                if(j!=0)
                {
                    j=alps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        i=0;
        j=0;
        while(i<n)
        {
            if(s[i]==b[j])
            {
                i++;
                j++;
            }
            if(j==bsize)
            {
                bstore.push_back(i-j);
                j=blps[j-1];
            }
            else if(s[i]!=b[j])
            {
                if(j!=0)
                {
                    j=blps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        vector<int> ans;
        for(int i=0,j=0;i<astore.size() && j<bstore.size();)
        {
            if(abs(astore[i]-bstore[j])<=k)
            {
                ans.push_back(astore[i]);
                i++;
            }
            else if(astore[i]<bstore[j])
                i++;
            else j++;
        }
        return ans;
    }
};