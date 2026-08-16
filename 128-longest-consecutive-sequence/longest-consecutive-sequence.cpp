class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st;

        for (auto x : nums) {
            st.insert(x);
        }
        int ans = 0;
        int len = 1;
        for (auto x : st) {

            if (st.find(x - 1) == st.end()) {

                int temp = x;
                while (st.find(temp+ 1) != st.end()) {
                    len++;
                    temp++;
                }

                ans = max(len, ans);
                len = 1;
            }
        }
        ans = max(len, ans);
        return ans;
    }
};