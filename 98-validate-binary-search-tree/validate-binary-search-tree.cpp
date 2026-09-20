class Solution {
public:
    void inorder(TreeNode* root, vector<int>& temp) {
        if (root == NULL)
            return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> temp;
        inorder(root, temp);
        for (int i = 0; i < temp.size(); i++) {
            if (i + 1 < temp.size() && temp[i] >= temp[i + 1]) {
                return false;
            }
        }
        return true;
    }
    // void maxHelper(TreeNode* root, long long& ans) {
    //     if (root == NULL) {
    //         return;
    //     }
    //     ans = max(ans,(long long) root->val);
    //     maxHelper(root->left, ans);
    //     maxHelper(root->right, ans);
    // }
    // long long maxBT(TreeNode* root) {
    //     long long ans = LLONG_MIN;
    //     maxHelper(root, ans);
    //     return ans;
    // }
    // void minHelper(TreeNode* root, long long& ans) {
    //     if (root == NULL) {
    //         return;
    //     }
    //     ans = min(ans, (long long)root->val);
    //     minHelper(root->left, ans);
    //     minHelper(root->right, ans);
    // }
    // long long minBT(TreeNode* root) {
    //     long long ans = LLONG_MAX;
    //     minHelper(root, ans);
    //     return ans;
    // }
    // void isBST(TreeNode* root, bool& finalans) {
    //     if (root == NULL)
    //         return;
    //     if (!((long long)root->val > maxBT(root->left) &&
    //          (long long) root->val < minBT(root->right))) {
    //         finalans = false;
    //         return;
    //     }
    //     isBST(root->left, finalans);
    //     isBST(root->right, finalans);
    // }
    // bool isValidBST(TreeNode* root) {
    //     if (root->left == NULL && root->right == NULL)
    //         return true; // single node
    //     cout << maxBT(root->left) << endl;
    //     cout << minBT(root->right) << endl;
    //     bool finalans = true;
    //     isBST(root, finalans);
    //     return finalans;
    // }
};