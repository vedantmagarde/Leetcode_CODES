class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices.back();
        vector<int> arr(n);
        for (int i = prices.size() - 1; i >= 0; i--) {
            arr[i] = max(maxi, prices[i]);
            maxi = max(maxi, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, arr[i] - prices[i]);
        }
        return ans;
    }
};