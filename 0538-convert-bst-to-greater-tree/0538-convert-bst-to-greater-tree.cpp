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
    
    void solve(TreeNode *root,vector<int>& a){
        if(!root) return;
        a.push_back(root->val);
        solve(root->left,a);
        solve(root->right,a);
    }
    
    void result(TreeNode *root,unordered_map<int,int>& mp){
        if(!root) return;
        root->val=mp[root->val];
        result(root->left,mp);
        result(root->right,mp);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> a;
        solve(root,a);
        
        sort(a.rbegin(),a.rend());
        int n=a.size();
        int sum=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=a[i];
            mp[a[i]]=sum;
        }
        
        result(root,mp);
        return root;
    }
};