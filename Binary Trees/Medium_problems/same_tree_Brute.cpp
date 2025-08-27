class Solution {
public:
   
    vector<int> preorderTraversal(TreeNode* root, vector<int> &ans) {
       
        if(root==NULL){
            ans.push_back(-1);
            return ans;
        }
        
        ans.push_back(root->val);
        preorderTraversal(root->left,ans);
        preorderTraversal(root->right,ans);
        return ans;
       
    }

    bool isSameTree(TreeNode *root1, TreeNode *root2){
        vector<int>ans1,ans2;
        preorderTraversal(root1,ans1);
        preorderTraversal(root2,ans2);
        return ans1==ans2;
    }
    
};