class Solution {
public:
    bool ispossi(string& a, string& b) {
        int s1 = a.length();
        int s2 = b.length();
        int size_diff = abs(s1 - s2);
        if (size_diff == 0)
            return false;
        int itr1 = 0, itr2 = 0;
        if (size_diff == 1) {
            while (itr1 < a.length() && itr2 < b.length()) {
                if (a[itr1] != b[itr2]) {
                    itr2++;
                    continue;
                }
                itr1++;
                itr2++;
            }
        }
        return itr1 == a.length();
    }
    int fun(vector<string>& words, int prev, int curr,
            vector<vector<int>>& dp) {
        if (curr == words.size())
            return 0;

        if (dp[prev + 1][curr] != -1)
            return dp[prev + 1][curr];
        int skip = fun(words, prev, curr + 1,dp);
        int take = 0;
        if (prev == -1 || ispossi(words[prev], words[curr]))
            take = 1 + fun(words, curr, curr + 1,dp);

        return dp[prev + 1][curr] = max(skip, take);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.length() < b.length(); });

        vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
        return fun(words, -1, 0,dp);
    }
};