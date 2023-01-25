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
    multiset<int> s;
    void doit(TreeNode *root)
    {
        if (!root)
            return;
        s.insert(root->val);
        doit(root->left);
        doit(root->right);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        multiset<int> t;
        s = t;
        doit(root1);
        doit(root2);

        vector<int> ans;
        // cout<<"jai"<<endl;

        for (auto x : s)
            ans.push_back(x);
        return ans;
    }
};