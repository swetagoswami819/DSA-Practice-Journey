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


       int LCA(TreeNode * root, int node1 , int node2){
        int ans;
        vector<int>arr1;
        vector<int>arr2;
        DFS(root,node1,arr1);
        DFS(root,node2,arr2);
        
        int ans = -1; // default if no LCA found
        int n = min(arr1.size(), arr2.size());

        
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i]){
               break;
            }
            ans=arr1[i];
           
        }
        return ans;
       }
}