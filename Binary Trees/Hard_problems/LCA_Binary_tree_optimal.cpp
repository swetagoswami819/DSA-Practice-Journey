class Solution
{
public:
    int LCA(TreeNode *root, int node1, int node2)
    {
         if (root == NULL)
        {
            return NULL;
        }

        if (root==node1 || root==node2)
        {
            return root;
        }

        TreeNode * left = lowestCommonAncestor(root->left, node1, node2);
        TreeNode * right = lowestCommonAncestor(root->right, node1, node2);

        if (left!=NULL && right!=NULL)
            return root; // both nodes found, root is LCA
        else if (left != NULL)
            return left; // found in left subtree
        else
            return right; // found in right subtree or -1
    }
     
};