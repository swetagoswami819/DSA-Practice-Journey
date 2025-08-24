#include<bits/stdc++.h>
using namespace std;
class Solution{
public :
    void all_traversals(TreeNode * root , vector<int>pre, vector<int>in, vector<int>post){
        stack <TreeNode* , int>st;
        if(root!=NULL){
            cout<<"root is null";
        }
        st.push(root,1);
        while(!st.empty()){
            auto it=st.top();
            st.pop();

            //preorder--
            //push the left side of tree

            if(it.second==1){
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
        
                if(it.first->left!=NULL){
                    st.push(it.first->left,1)
                }
            }

            //Inorder
            //push the right side of tree
            else if(it.second==2){
                in.push_back(it.first->data);
                it.second++;
                st.push(it);

                if(it.first->right!=NULL){
                    st.push(it.first->right ,1);
                }
            }

            //postorder
            //push the node
            else{
                post.push_back(it.first->data);
            }
            
        }
    }

};