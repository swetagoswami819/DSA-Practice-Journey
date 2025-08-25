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
    }

    int diameter(TreeNode * root , int  &ans){
        if(root==NULL){
            return 0;
        }
        else{
            int lheight=height(root->left);
            int rheight=height(root->right);

            ans=max(ans,lheight+rheight);
            diameter(root->left,ans);
            diameter(root->right,ans);
        }


    }