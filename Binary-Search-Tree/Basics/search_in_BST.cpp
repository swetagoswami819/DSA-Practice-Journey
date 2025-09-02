class Solution{
    public : 
       TreeNode * searchBST(TreeNode * root, int val){
        while(root!=NULL && root->data!=val){
            root=root->data>val ? root->left : root->right;
        }
        return root;
       }
}