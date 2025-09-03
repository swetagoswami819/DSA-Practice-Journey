#include<bits/stdc++.h>
using namespace std;
class Solution{
    public : 
        int floor_BST(TreeNode * root , int key){
            int ans= -1;
            while(root!=NULL){
            
            if (root->val == key) {
                return root->val; // exact floor
            }
            
            if(key>root->val){
                ans=root->val;
                root=root->right;
            }
            else{
                
                root=root->left;
            }
        }
        return ans;

        }
       
        
};