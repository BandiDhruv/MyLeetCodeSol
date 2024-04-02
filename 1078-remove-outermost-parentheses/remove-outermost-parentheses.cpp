class Solution {
public:
    string removeOuterParentheses(string s) {
        int op = 0;
        string ans = "";

        for(char ch: s) {
            if(ch == '(') {
                if(op != 0) ans += "(";
                op++;
            } else {
                op--;
                if(op != 0) ans += ")";
            }
        }
        return ans;
    }
};