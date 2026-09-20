class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr,
                int i) {

        if (i == nums.size()) { // Hitting base case....
            ans.push_back(curr);
            return;
        }

        // Taking current elements..........////////
        curr.push_back(nums[i]);
        helper(nums, ans, curr, i + 1);
        curr.pop_back();

        // Skipping the Ellemnts.... for duplicates choices
        while (i+1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(nums, ans, curr, i+1 );
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        helper(nums, ans, curr, 0);
        return ans;
    }
};