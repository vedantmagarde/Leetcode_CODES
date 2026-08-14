class Solution {
public:
    vector<int> right_bound_small(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        int i = arr.size() - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            st.empty() ? ans.push_back(arr.size()) : ans.push_back(st.top());
            st.push(i);
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> left_bound_small(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        int i = 0;
        while (i < arr.size()) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
            st.push(i);
            i++;
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        // int mod = 1000000007;
        vector<int> right_b_arr = right_bound_small(arr);
        vector<int> left_b_arr = left_bound_small(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long ans1 = right_b_arr[i] - i;
            long long ans2 = i - left_b_arr[i];

            // long long total_subarrays = (ans1 * ans2) % mod;
            // long long contribution = (total_subarrays * arr[i]) % mod;

            // ans = (ans + contribution) % mod;

            long long total_subarrays = ans1 * ans2;
            long long contribution = total_subarrays * arr[i];

            ans = ans + contribution;
        }
        return ans;
    }
    vector<int> right_bound_larger(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        int i = arr.size() - 1;
        while (i >= 0) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            st.empty() ? ans.push_back(arr.size()) : ans.push_back(st.top());
            st.push(i);
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> left_bound_larger(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        int i = 0;
        while (i < arr.size()) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            st.empty() ? ans.push_back(-1) : ans.push_back(st.top());
            st.push(i);
            i++;
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        long long ans = 0;
        // int mod = 1000000007;
        vector<int> right_b_arr = right_bound_larger(arr);
        vector<int> left_b_arr = left_bound_larger(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long ans1 = right_b_arr[i] - i;
            long long ans2 = i - left_b_arr[i];

            // long long total_subarrays = (ans1 * ans2) % mod;
            // long long contribution = (total_subarrays * arr[i]) % mod;

            // ans = (ans + contribution) % mod;

            long long total_subarrays = ans1 * ans2;
            long long contribution = total_subarrays * arr[i];

            ans = ans + contribution;
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};