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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //dfs
        int cursum=0;
        vector<int> cur;
        vector<vector<int>> ans;
        if(!root){return ans;}
        dfs(root,cur,cursum,targetSum,ans);
        return ans;
    }
    
    void dfs(TreeNode* &root, vector<int> &cur, int &cursum, int &targetSum, vector<vector<int>> &ans){
        cur.push_back(root->val);
        cursum += root->val;
        if(!(root->left) and !(root->right) and targetSum==cursum){
            ans.push_back(cur);
            cur.pop_back();
            cursum -= root->val;
            return;
        }
        else if(!(root->left) and !(root->right) and targetSum!=cursum){
            cur.pop_back();
            cursum -= root->val;
            return;
        }
        if(root->left){
            dfs(root->left,cur,cursum,targetSum,ans);
        }
        
        if(root->right){
            dfs(root->right,cur,cursum,targetSum,ans);
        }
        cur.pop_back();
        cursum -= root->val;
        return;
    }
};
