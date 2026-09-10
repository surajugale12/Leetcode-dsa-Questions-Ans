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
    typedef long long ll;
    pair<ll, ll> helper(TreeNode* node, ll& res){
        if(node==NULL) return {0LL, 0LL};
        pair<ll, ll> p1 = helper(node->left,  res);
        pair<ll, ll> p2 = helper(node->right, res);
        ll sum = p1.first + p2.first + node->val;
        ll cnt = p1.second + p2.second + 1;
        ll avg = sum/cnt;
        if(node->val == avg) res++;
        return {sum, cnt};
    }
    // ll helper(TreeNode* node, ll cnt, ll sum){
    //     if(node==NULL) return 0;
    //     if(node->val == (sum/cnt)) return 1;
    //     return helper(node->left, cnt+1, sum+node->val)+
    //     helper(node->right, cnt+1, sum+node->val);
    // }
    int averageOfSubtree(TreeNode* root) {
        ll ans=0;
        helper(root, ans);
        return (int)ans;
    }
};