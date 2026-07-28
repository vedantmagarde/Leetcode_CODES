class Solution {
public:
    void fun(vector<int>& arr, TreeNode* root) {
        if (root == NULL)
            return;
        fun(arr, root->left);
        arr.push_back(root->val);
        fun(arr, root->right);
    }

    bool findTarget(TreeNode* root, int k) {


        vector<int> arr;
        fun(arr, root);
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            if (arr[l] + arr[r] == k)
                return true;
            else if (arr[l] + arr[r] < k)
                l++;
            else
                r--;
        }
        return false;
    }
};