class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for (auto x : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && x < 0) {
                if (st.top() < abs(x)) {
                    st.pop();
                } else if (st.top() == abs(x)) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(x);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};