#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 
       bool childrenSum(TreeNode * root){

        if(root==NULL){
            return true;
        }

        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        int leftVal= (root->left) ? root->left->val : 0;
        int rightVal = (root->right) ? root->right->val : 0;

        if(root->val==leftVal+rightVal){
            return childrenSum(root->left) && childrenSum(root->right);
        }
        return false;

       }
};