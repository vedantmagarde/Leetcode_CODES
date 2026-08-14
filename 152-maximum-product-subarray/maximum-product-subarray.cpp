class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int prod1 = 1;
        for (int i = 0; i < nums.size(); i++) {
            prod1 *= nums[i];
            ans = max(ans, prod1);
            if (prod1 == 0)
                prod1 = 1;
        }
        int prod2 = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod2 *= nums[i];
            ans = max(ans, prod2);
            if (prod2 == 0)
                prod2 = 1;
        }

        return ans;
    }
};