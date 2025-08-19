class Solution {
   
public:
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<Treenode* >s;
        s.push(root);
        while(!s.empty()){
            root=s.top();
            s.pop();
            ans.push_back(node->val);  
            if(root->right!=NULL) s.push(root->right);
            if(root->left!=NULL) s.push(root->left);
           
    }
    return ans;
}
};