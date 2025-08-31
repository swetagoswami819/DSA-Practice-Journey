#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    
       bool DFS(TreeNode *root, int x, vector<int> &ds){
 
        if(!root) return  false;

         ds.push_back(root->val);
        if(root->val==x){
            return true;
        }
       
        if(DFS(root->left,x,ds) || DFS(root->right,x,ds)){
            return true;
        }
        ds.pop_back();
        return false;   
       }


       vector<int> rootToNodeTraversal(TreeNode * root){
        vector<int>ds;
           if(root==NULL) return ds;
           DFS(root,7,ds);
           return ds;
       }
}