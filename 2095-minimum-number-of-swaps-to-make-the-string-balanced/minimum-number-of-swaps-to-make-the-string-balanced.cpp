class Solution {
public:
    int minSwaps(string s) {
        int op=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[')op++;
            else{
                if(op>0)op--;
            }
        }
        return (op+1)>>1;
    }
};