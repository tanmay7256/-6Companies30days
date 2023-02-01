class Solution
{
public:
    vector<int> ans;
    int N;
    Solution(vector<int> &w)
    {
        for (int i = 1; i < w.size(); i++)
            w[i] += w[i - 1];
        ans = w;
        N = ans[ans.size() - 1];
    }

    int pickIndex()
    {
        int n = rand() % N;
        int i = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */