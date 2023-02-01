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
    map<TreeNode *, pair<int, int>> umap;
    pair<int, int> find(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        if (umap.find(root) != umap.end())
            return umap[root];
        pair<int, int> l = find(root->left);
        pair<int, int> r = find(root->right);

        umap[root] = {(root->val + l.second + r.second), max(max((l.second + r.second), max((l.first + r.second), (l.second + r.first))), (l.first + r.first))};
        return umap[root];
    }
    int rob(TreeNode *root)
    {
        umap.clear();
        pair<int, int> p = find(root);
        return max(p.first, p.second);
    }
};