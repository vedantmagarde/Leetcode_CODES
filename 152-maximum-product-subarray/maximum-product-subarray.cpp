class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int prod1 = 1, prod2 = 1, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            prod1 *= nums[i];
            prod2 *= nums[n - i - 1];
            ans = max({ans, prod1, prod2});
            if (prod1 == 0)
                prod1 = 1;
            if (prod2 == 0)
                prod2 = 1;
        }

        return ans;
    }
};