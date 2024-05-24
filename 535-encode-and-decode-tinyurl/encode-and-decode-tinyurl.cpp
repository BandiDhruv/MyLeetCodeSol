class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string>mp1,mp2;
    int cnt=0;
    string encode(string longUrl) {
        mp1[longUrl]=to_string(cnt++);
        mp2[mp1[longUrl]]=longUrl;
        return mp1[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));