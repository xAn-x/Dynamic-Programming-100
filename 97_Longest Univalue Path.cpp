// https://leetcode.com/problems/longest-univalue-path/
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
        if(root==nullptr or (root->left==nullptr and root->right==nullptr)) return 0;
        
        int l=helper(root->left,res);
        int r=helper(root->right,res);
        
        int temp=0;
        if(root->left!=nullptr and root->val==root->left->val) temp=max(temp,1+l);
        if(root->right!=nullptr and root->val==root->right->val) temp=max(temp,1+r);
        
        
        int ans=temp;
        if(root->left!=nullptr and root->val==root->left->val and root->right!=nullptr and root->val==root->right->val) ans=max(ans,2+l+r);
        
        res=max(res,ans);
        
        return temp;
        return temp;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int res=0,ht=0;
        helper(root,res);
        return res;
    }
};