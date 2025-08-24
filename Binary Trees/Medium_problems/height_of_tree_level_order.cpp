class Solution {
public:
    vector<vector<int>> height(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        int cnt=0;
        q.push(root);
        while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                    TreeNode  * node = q.front();
                    q.pop();
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);  
                }
                cnt++;   
            }
            return cnt;
        }
          
    }
};