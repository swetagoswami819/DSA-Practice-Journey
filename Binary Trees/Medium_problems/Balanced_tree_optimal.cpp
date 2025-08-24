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
            if(lheight==-1) return -1;
            int rheight=height(root->right);
            if(rheight==-1) return -1;

            if(abs(lheight-rheight)>1) return -1;
            
            return 1+max(lheight, rheight);

           
        }

       }
        bool Balanced_Tree(TreeNode *root){
          
            if(height(root)==-1){
                return false;
            }
            return true;
        }


}