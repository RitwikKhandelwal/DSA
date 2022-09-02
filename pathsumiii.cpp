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
    int pathSum(TreeNode* root, int targetSum) {
        //dfs
        long int cursum=0;
        vector<long int> cur; // sums from root to intermediate nodes of current path
        int ans=0;
        if(!root){return 0;}
        dfs(root,cur,cursum,targetSum,ans);
        return ans;
    }
    
    void dfs(TreeNode* &root, vector<long int> &cur,long int &cursum, int &targetSum, int &ans){
        cur.push_back(cursum+root->val);
        cursum += root->val;
        if(cursum==targetSum){
            ans++;
        }
        for(int i = 0;i<(cur.size()-1);i++){
            if((cursum-cur[i])==targetSum){
                ans++;
            }
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
