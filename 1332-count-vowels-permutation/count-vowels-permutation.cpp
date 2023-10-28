// class Solution {
// public:
//     int mod=1e9+7;
//     unordered_map<char,vector<char>>mp;
//     vector<char> last;
//     // int solve(int idx,int n,char last)
//     // {
//     //     int count=0;
//     //     if(n==0)
//     //         return 1;
//     //     for(auto it:mp[last])
//     //     {
//     //         count=(count+solve(idx,n-1,it))%mod;
//     //     }
//     //     return count;
//     // }
//      int solvemem(int idx, int n, char last, vector<vector<int>> &dp) {
//         if (n == 0)
//             return 1;
//         if (dp[idx][n]!=-1)
//             return dp[idx][n];
//         long long count = 0;
//         for (auto it : mp[last]) {
//             count=count%mod;
//             count += (solvemem(idx, n - 1, it, dp));
//             count=count%mod;
//         }
       
//         return dp[idx][n]=count%mod;
//     }

//     int countVowelPermutation(int n) {
//         mp['a'].push_back('e');
//         mp['e'].push_back('a');
//         mp['e'].push_back('i');
//         mp['i'].push_back('e');
//         mp['i'].push_back('a');
//         mp['i'].push_back('o');
//         mp['i'].push_back('u');
//         mp['o'].push_back('u');
//         mp['o'].push_back('i');
//         mp['u'].push_back('a');
//         last.resize(5);
//         last[0] = 'a';
//         last[1] = 'e';
//         last[2] = 'i';
//         last[3] = 'o';
//         last[4] = 'u';

//         int count = 0;
//         vector<vector<int>> dp(5, vector<int>(n + 1, -1));

//         for (int i = 0; i < 5; i++) {
//             count += (solvemem(i, n - 1, last[i], dp)) ;
//             count=count%mod;
//         }
//         return count;
//     }
// };
class Solution {
    int mod = 1e9+7 ;
    int helper(char prev , map<char,string>& next , int len ,int n , vector<vector<int>>& dp){
        if(len >= n) return 1 ;
        if(dp[len][prev-'a'] != -1) return dp[len][prev-'a'] ;

        long long temp = 0 ;
        for(char ng : next[prev]){
            temp += helper(ng , next , len+1 , n ,dp);
            temp = temp%mod ;
        }
        return dp[len][prev-'a'] = temp%mod ;
    }
public:
    int countVowelPermutation(int n) {
        map<char,string> next ;
        next['a'] = "e";
        next['e'] = "ai" ;
        next['i'] = "aeou" ;
        next['o'] = "iu" ;
        next['u'] = "a" ;
        vector<char> arr = {'a' , 'e' , 'i' , 'o' , 'u'};
        vector<vector<int>> dp(n , vector<int>(26,-1));
        long long cnt = 0 ;
        for(int i=0;i<arr.size() ; i++){
            cnt += helper( arr[i] , next ,1 ,n ,dp);
            cnt = cnt%mod ;
        }

        return cnt ;
    }
};
