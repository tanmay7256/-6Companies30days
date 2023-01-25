class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int n = cards.size();
        unordered_map<int, int> umap;
        int ans = INT32_MAX;
        for (int i = 0; i < n; i++)
        {
            if (umap[cards[i]])
                ans = min(ans, i + 2 - umap[cards[i]]);
            umap[cards[i]] = i + 1;
        }
        if (ans == INT32_MAX)
            ans = -1;
        return ans;
    }
};