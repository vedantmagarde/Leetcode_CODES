class Solution {
public:
    void fun(vector<int>& nums, vector<int>& temp, vector<bool>& visited,
             vector<vector<int>>& ans) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (!visited[i]) {
                temp.push_back(nums[i]);
                visited[i] = true;
                fun(nums, temp, visited, ans);
                visited[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(nums.size(), false);
        fun(nums, temp, visited, ans);
        return ans;
    }
};