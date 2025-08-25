#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
       int height(TreeNode *root, int &ans){
        if(root==NULL){
            return 0;
        }
        else{
            int lheight=height(root->left,ans);
            int rheight=height(root->right,ans);

            ans=max(ans,lheight+rheight);

            return 1+max(lheight, rheight);
        }

       }
    }
