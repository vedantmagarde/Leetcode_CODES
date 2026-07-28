class Solution {
public:
    void leftwala(TreeNode* root, stack<TreeNode*>& leftStack) {
        while (root != NULL) {
            leftStack.push(root);
            root = root->left;
        }
    }
    void rightwala(TreeNode* root, stack<TreeNode*>& rightStack) {
        while (root != NULL) {
            rightStack.push(root);
            root = root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        stack<TreeNode*> leftStack, rightStack;

        leftwala(root, leftStack);
        rightwala(root, rightStack);

        while (leftStack.top()->val < rightStack.top()->val) {
            int sum = leftStack.top()->val + rightStack.top()->val;

            if (sum == k)
                return true;
                
            else if (sum < k) {
                TreeNode* temp = leftStack.top();
                leftStack.pop();
                leftwala(temp->right, leftStack);
            } else {
                TreeNode* temp = rightStack.top();
                rightStack.pop();
                rightwala(temp->left, rightStack);
            }
        }
        return false;
    }
};