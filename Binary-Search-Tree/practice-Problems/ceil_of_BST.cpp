#include<bits/stdc++.h>
using namespace std;
class Solution{
    public : 
        int ceil_BST(TreeNode * root , int key){
            int ans= -1;
            while(root!=NULL){
                if(root->val==key ){
                    ans=root->val;
                    return ans;
                }
            if(key>root->val){
                
                root=root->right;
            }
            else{
                ans=root->val;
                root=root->left;
            }
        }
        return ans;

        }
       
        
};