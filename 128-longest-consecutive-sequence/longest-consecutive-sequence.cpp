class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto x : nums) {
            st.insert(x);
        }
        int ans = 0;
        int len = 1;
        for (auto x : st) {
            if (st.find(x - 1) == st.end()) {
                int temp = x;
                while (st.find(temp + 1) != st.end()) {
                    temp++;
                    len++;
                }
                ans = max(ans, len);
                len = 1;
            }
        }
        return ans;
    }
};