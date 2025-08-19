class Solution {
   
public:
    vector<int>ans;
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        stack<int>st;
        TreeNode * node=root;

        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                ans.push_back(topNode->val);
                node=node->right;
            }

        }
           
    return ans;
}
};