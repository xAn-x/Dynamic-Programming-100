/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode*root,int &res){
        if(root==nullptr){
            return -1e7;
        }
        
        int lft=helper(root->left,res);
        int rt=helper(root->right,res);
        
        //If I decide to pass to upper root 
        int temp =max({root->val,lft+root->val,rt+root->val});
        
        
        //ans max(include-root,not-include root)
        int ans=max(temp,lft+root->val+rt);
        res=max(res,ans);
        
        //Return temp 
        return temp;
    }
    
    
    int maxPathSum(TreeNode* root) {
        int res=-1e7;
        helper(root,res);
        
        return res;
    }
};