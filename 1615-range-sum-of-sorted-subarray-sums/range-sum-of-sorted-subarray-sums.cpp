class Solution {
public:
    long long mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> temp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(), temp.end());
        vector<long long> pre(temp.size());
        pre[0] = temp[0] % mod;
        for (int i = 1; i < temp.size(); i++) {
            pre[i] = (pre[i-1] + temp[i]) % mod;
        }
        long long result = pre[right-1] - (left >1 ? pre[left-2] : 0);
        if (result < 0) {
            result += mod;
        }
        return result % mod;
    }
};
