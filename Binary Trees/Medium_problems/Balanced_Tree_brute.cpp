#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :

        int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        else{
            int lheight=height(root->left);
            int rheight=height(root->right);

            return 1+max(lheight, rheight);

           
        }

       }
        bool Balanced_Tree(TreeNode *root){
            if(root=NULL){
                return true;
            }
            int lh=height(root->left);
            int rh=height(root->right);
            if(abs(lh-rh)<=1 && Balanced_Tree(root->left) && Balanced_Tree(root->right)){
                return true;
            }
            return false;
        }


}