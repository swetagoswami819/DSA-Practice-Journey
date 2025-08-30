#include<bits/stdc++.h>
using namespace std;

class Solution{
    public :
        map<int ,multiset<pair<int , int>>>mp;
        void verticalOrder(TreeNode * root , int hd , int level){
            if(root==NULL){
                return;
            }
            mp[hd].insert({level,root->val});
            verticalOrder(root->left, hd-1, level+1);
            verticalOrder(root->right,hd+1, level+1);
        
        }


        vector<vector<int>> verticalTraversal(TreeNode * root){
            vector<vector<int>>ans;
            verticalOrder(root,0,0);
            for(auto it:mp){
               
                vector<int>col;
                for(auto p : it.second){
                    col.push_back(p.second);

                }
                ans.push_back(col);
            }
            return ans;

        }
};