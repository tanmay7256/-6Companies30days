class trie
{
public:
    unordered_map<int, trie *> umap;
};
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int ans = 0;
        trie *root = new trie();
        for (int i = 0; i < nums.size(); i++)
        {
            int c = 0;
            trie *t = root;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % p == 0)
                    c++;
                if (c > k)
                    break;
                if (!(t->umap[nums[j]]))
                {
                    t->umap[nums[j]] = new trie();
                    ans++;
                }
                t = t->umap[nums[j]];
            }
        }
        return ans;
    }
};