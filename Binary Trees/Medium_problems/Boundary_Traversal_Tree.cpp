class Solution
{
public:
    vector<int> ans;
    void left_Traversal(TreeNode *root)
    {   
        TreeNode * curr=root->left;

        while(curr!=NULL){
            if(!(curr->left==NULL  && curr->right==NULL)){ //skip the leaf node
                ans.push_back(curr->val);
            }

            curr= (curr->left!=NULL) ? curr->left : curr->right; //go to left if possible else go to right
        
        }
       
    }

    void leaf_Traversal(TreeNode *root)
    {   
        if(!root) return;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
          
        }
        leaf_Traversal(root->left);
        leaf_Traversal(root->right);
    }

    void right_Traversal(TreeNode *root)
    {   vector<int>level;
        TreeNode * curr=root->right;

        while(curr!=NULL){
            if(!(curr->left==NULL  && curr->right==NULL)){ //skip the leaf node
                level.push_back(curr->val);
            }

           curr= (curr->right!=NULL) ? curr->right : curr->left; //go to right if possible else go to left
        
        }
        reverse(level.begin(),level.end());
        for(auto it:level){
            ans.push_back(it);
        }
        
    }


    vector<int> Boundary_Traversal(TreeNode *root)
    {
        if(root==NULL) return ans;
        else{
        ans.push_back(root->val);
        left_Traversal(root);
        leaf_Traversal(root);
        right_Traversal(root);
        }
        return ans;
    }
}