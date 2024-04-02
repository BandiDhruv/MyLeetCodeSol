class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> str;
        string word;
        while (ss >> word) {
            str.push_back(word);
        }
        int n = str.size();
        string ans ="";
        while (n > 0) {
            ans += str[n - 1];
            if (n != 1) ans += " ";
            n--;
        }
        return ans;
    }
};