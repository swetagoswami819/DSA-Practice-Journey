class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        stack<TreeNode*> st1;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            ans.push_back(node->val);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        // Reverse the order of elements in ans to get postorder
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
