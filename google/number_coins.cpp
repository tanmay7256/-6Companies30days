class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end(), greater<int>());
        int i = 1, ans = 0, j = piles.size();
        while (i < j)
        {
            ans += piles[i];
            i += 2;
            j--;
        }
        return ans;
    }
};