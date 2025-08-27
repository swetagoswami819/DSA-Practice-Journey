class Solution {
public:
    vector<vector<int>> zigzagTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode  * node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            if(cnt%2==0){
                ans.push_back(level);
                cnt++;
            }
            else{
                reverse(level.begin(),level.end());
                ans.push_back(level);
                cnt++;
            }
        }
        return ans;
        
    }
};