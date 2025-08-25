#include<bits/stdc++.h>
using namespace std;

class Solution{
    int ans;

    public :
    Solution(){
        ans=INT_MIN;
    }
       int helper(TreeNode *root){
        if(root==NULL){
            return 0;
        }
       
            int lsum=max(0,helper(root->left));
            int rsum=max(0,helper(root->right));
            
            ans=max(ans,root->val+lsum+rsum);
       
        return root->val+max(lsum,rsum);

       }
    
  int maxiSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};