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
        if (root != NULL && root->left == NULL && root->right == NULL)
            return false;
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

        // vector<int> brr;
        // fun(arr, root);
        // for (int i = 0; i < arr.size(); i++) {
        //     brr.push_back(k - arr[i]);
        // }
        // reverse(brr.begin(), brr.end());
        // int i1 = 0, i2 = 0, n = arr.size();
        // while (i1 < n && i2 < n) {
        //     if (arr[i1] == brr[i2] && arr[i1] * 2 != k)
        //         return true;
        //     if (arr[i1] < brr[i2]) {
        //         i1++;
        //     } else {
        //         i2++;
        //     }
        // }
        // return false;
    }
};