class Solution {
public:
    int minimumLength(string s) {
        int rem=0;
        int i=0,j=s.size()-1;
        bool f=false;
        while(i<j)
        {
            while(i<s.size() && j>=0 && s[i]==s[j])
            {
                if(i>=j){
                    f=true;
                    break;
                }
                i++;
                j--;
                rem+=2;
            }    
            if(f)break;
            while(i>0 && s[i]==s[i-1]){
                if(i>=j){
                    f=true;
                    break;
                }
                i++;
                rem++;
            }
            if(f)break;
            while(j<s.size() && s[j]==s[j+1]){
                if(i>=j){
                    f=true;
                    break;
                }
                j--;
                rem++;
            }
            if(f)break;
            // i++;
            // j--;
            if(s[i]!=s[j])break;
        }
        cout<<s.size()<<" "<<rem;
        if(s.size()==1)return 1;
        if(s.size()==3 && rem+1==s.size())return 1;
        else if(s.size()%2==1 && rem+1==s.size())return 0;
        return s.size()-rem;
    }
};