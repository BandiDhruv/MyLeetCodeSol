class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> t;
        for(int i=0;i<(1<<n);i++)
            t.push_back(i^(i>>1));
        return t;
    }
};