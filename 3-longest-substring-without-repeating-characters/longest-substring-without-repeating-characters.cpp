class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0 || n == 1)
            return n;

        unordered_map<char, int> mp;

        int ans = 0;
        int l = 0, r = 0;
        while (r < n) {
            mp[s[r]]++;

            if (mp.size() != r - l + 1) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};