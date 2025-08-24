#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
       void height(TreeNode *root){
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