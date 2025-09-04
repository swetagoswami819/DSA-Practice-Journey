#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 
        TreeNode * insert_BST(TreeNode  *root, int val){
             if (root == NULL) {
            return new TreeNode(val);  // new root
        }
          
            TreeNode * temp=root;
            while(temp){
                if(val<=temp->val){
                    if(temp->left==NULL){
                        temp->left = new TreeNode(val);
                        break;
                    }
                    else{
                        temp=temp->left;
                    }

                }
                else{
                    if(temp->right==NULL){
                        temp->right=new TreeNode(val);
                        break;

                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
            return root;
            
        }
};