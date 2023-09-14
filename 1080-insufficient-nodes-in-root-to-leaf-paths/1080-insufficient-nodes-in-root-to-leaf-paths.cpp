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
    
    pair<int,bool> result(TreeNode *root,int limit,int sum){
        if(!root) return {0,false};
        
        
        
        pair<int,bool> l= result(root->left,limit,sum+root->val);
        pair<int,bool> r= result(root->right,limit,sum+root->val);
        
        int val;
        if(root->left && root->right) val=root->val+ max(l.first,r.first);
        else if(root->left) val=root->val+l.first;
        else if(root->right) val=root->val+ r.first;
        else val=root->val;
        
        bool sufficient=true;
        if(val+sum<limit) sufficient=false;
        
        if(l.second==false){
            root->left=NULL;
        }
        if(r.second==false){
            root->right=NULL;
        }
        
        
        
        return {val,sufficient};
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        pair<int,bool> ans= result(root,limit,0);
        
        if(ans.second==false) return NULL;
        return root;
    }
};

