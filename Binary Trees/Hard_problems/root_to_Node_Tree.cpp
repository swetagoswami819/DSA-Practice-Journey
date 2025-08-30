#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>>ans;
    vector<int>ds;
       void DFS(TreeNode *root, int x){
 
        if(!root) return  false;

        if(root->val==x){
            return true;
        }

        if(DFS(root->left,x) || DFS(root->right,x)){
            return true;
        }
        arr.pop_back(x);
        return false;   
       }


       vector<vector<int>> rootToNodeTraversal(TreeNode * root){
           if(root==NULL) return NULL;
           DFS(root,7);
           return ans;
       }
}