class Solution {
public:
    void fun(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
             vector<bool>& visi) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visi[i] == false) {
                temp.push_back(nums[i]);
                visi[i] = true;
                fun(nums, ans, temp, visi);
                temp.pop_back();
                visi[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visi(nums.size(),false);
        vector<vector<int>> ans;

        fun(nums,ans,temp,visi);
        return ans;
    }
};