class Solution {
public:
    void f(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp,
           int itr, int& sum, int target) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target)
            return;

        for (int i = itr; i < candidates.size(); i++) {
            if (i - 1 >= itr && candidates[i] == candidates[i - 1])
                continue;

            temp.push_back(candidates[i]);
            sum += candidates[i];

            f(candidates, ans, temp, i + 1, sum, target);

            sum -= candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        f(candidates, ans, temp, 0, sum, target);
        return ans;
    }
};