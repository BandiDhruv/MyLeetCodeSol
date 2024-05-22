class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int c=0;
        for(int i=0;i<s[0].size();i++){
            char ch=s[0][i];
            bool f=true;
            for(int j=1;j<s.size();j++){
                if(ch!=s[j][i]){f=false;break;}
            }
            
            if(!f)break;
            cout<<c<<endl;
            c++;
        }
        cout<<c;
        return s[0].substr(0,c);
    }
};