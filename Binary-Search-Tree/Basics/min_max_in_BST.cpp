class Solution {
public:
    vector<int> min_max_BST(TreeNode *root) {
        if (!root) return {};

        TreeNode* temp = root;
        int minVal = INT_MAX, maxVal = INT_MIN;

        // find min (leftmost)
        while (temp->left) {
            temp = temp->left;
        }
        minVal = temp->val;

        temp = root;
        // find max (rightmost)
        while (temp->right) {
            temp = temp->right;
        }
        maxVal = temp->val;

        return {minVal, maxVal};
    }
};
