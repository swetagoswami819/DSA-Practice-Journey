#include<bits/stdc++.h>
using namespace std;
class Solution{
public :
    void all_traversals(TreeNode * root , vector<int>pre, vector<int>in, vector<int>post){
        stack <TreeNode* , int>st;
        if(root!=NULL){
            cout<<"root is null";
        }
        
        pre.push_back(root->data);
        all_traversals(root->left , pre, in , post);
        in.push_back(root->data);
        all_traversals(root->right , pre, in , post);
        post.push_back(root->data);

    }
};