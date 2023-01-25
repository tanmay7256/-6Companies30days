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
class Solution
{
public:
    int ans;
    pair<int, int> find(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        double avg;
        auto lft = find(root->left);
        auto ryt = find(root->right);
        avg = (lft.first + ryt.first + root->val) / double(lft.second + ryt.second + 1);
        int a = avg;
        if (a == root->val)
        {
            ans++;
            // cout<<a<<endl;
        }
        return {lft.first + ryt.first + root->val, lft.second + ryt.second + 1};
    }
    int averageOfSubtree(TreeNode *root)
    {
        ans = 0;
        auto a = find(root);
        return ans;
    }
};