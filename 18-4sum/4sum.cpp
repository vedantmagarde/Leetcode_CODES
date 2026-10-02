class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum =
                        (long long)nums[l] + nums[i] + nums[j] + nums[r];
                    if (sum > target)
                        r--;
                    else if (sum < target)
                        l++;
                    else {
                        ans.push_back({nums[l], nums[i], nums[j], nums[r]});

                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r - 1] == nums[r])
                            r--;

                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};