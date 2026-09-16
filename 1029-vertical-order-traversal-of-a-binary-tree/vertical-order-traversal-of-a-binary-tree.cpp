class Solution {
public:
    void fun(TreeNode* root, unordered_map<int, vector<pair<int, int>>>& mp,
             int row, int col) {
        if (root == NULL)
            return;
       mp[col].push_back({row, root->val});

        fun(root->left, mp, row + 1, col - 1);
        fun(root->right, mp, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int, int>>> mp; // col --> <row,val>
        fun(root, mp, 0, 0);
        vector<vector<int>> ans;
        vector<pair<int, vector<pair<int, int>>>> arr;

        for (auto x : mp) {
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            sort(arr[i].second.begin(), arr[i].second.end(),
                 [](pair<int, int>& a, pair<int, int>& b) {
                     if (a.first == b.first)
                         return a.second < b.second;
                     return a.first < b.first;
                 });
        }

        for (int i = 0; i < arr.size(); i++) {
            vector<int>temp;
            for (auto x : arr[i].second) {
                temp.push_back(x.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};