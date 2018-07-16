/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> v;
    int s;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        s=sum;  
        vector<int> tmp;
        if(root)
            dfs(root,tmp,0);
        return v;
    }
    
    void dfs(TreeNode *root,vector<int> tmp,int t){
        t+=root->val;
        tmp.push_back(root->val);

        if(s==t&&!root->left&&!root->right){
            v.push_back(tmp);  
            return;
        }
       
        if(root->left){
            dfs(root->left,tmp,t);
        }
        if(root->right){
            dfs(root->right,tmp,t);
        }
    }
};

