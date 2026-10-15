class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        unordered_map<char, int> mp;
        int count = 0;
        while (i < n && j < n) {
            
            mp[s[j]]++;

            while (mp.size() >= 3) {
                count += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            j++;
        }
        return count;
    }
};