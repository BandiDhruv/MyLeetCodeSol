class Solution {
public:
    int compress(vector<char>& s) {
        int i=0,k=0,n=s.size();
        while(i<n){
            int cnt=1;
            char last=s[i];
            int j=i+1;
            while(j<n && last==s[j]){
                cnt++;
                j++;
            }
            s[k++]=s[i];
            if(cnt>1){
                if(cnt<10){
                    s[k++]=(char)(cnt+'0');
                }
                else{
                    int temp=cnt;
                    string st;
                    while(temp>0){
                        int hi=temp%10;
                        temp/=10;
                        st.push_back(hi+'0');
                    }
                    for(int p=st.size()-1;p>=0;p--){
                        s[k++]=st[p];
                    }
                }
            }
            i=j;
        }    
        return k;
    }
};