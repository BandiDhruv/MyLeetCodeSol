class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int cnt=0;
        while(s.size()!=1){
            int i=s.size()-1;
            string temp=s;
            if(s[i]=='1'){
                cout<<s<<endl;
                int j=temp.size()-1;
                // temp[temp.size()-1]='0';
                while(j>=0){
                    if(temp[j]=='0'){temp[j]='1';break;}
                    j--;
                }
                if(j==-1){
                    int p=temp.size();
                    temp.clear();
                    temp.push_back('1');
                    while(p--){temp.push_back('0');}
                }
                temp[temp.size()-1]='0';
                cnt++;
            }
            s.clear();
            for(int i=0;i<temp.size()-1;i++){
                s.push_back(temp[i]);
            }
            cnt++;
        }
        return cnt;
    }
};