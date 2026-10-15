class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
        int n = nums.size();
        int presum = 0;
        mp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            int ele = presum - k;
            if (mp.find(ele) != mp.end()) {
                ans += mp[ele];
            }
            mp[presum]++;
        }

        return ans;
    }
};