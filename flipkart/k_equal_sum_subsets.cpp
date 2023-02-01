class Solution
{
public:
    unordered_map<string, int> umap;
    int find(vector<int> &nums, int k, string s, int n, int sum, int osum)
    {
        if (sum > osum)
            return 0;
        if (sum == osum)
        {
            k--;
            sum = 0;
        }
        if (k == 0)
            return 1;
        if (umap.find(s) != umap.end())
            return umap[s];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                ans = max(ans, find(nums, k, s, n, sum + nums[i], osum));
                if (ans)
                    return umap[s] = 1;
                s[i] = '0';
            }
        }
        return umap[s] = 0;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        umap.clear();
        int n = nums.size();
        string s(n, '0');
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % k)
            return 0;
        return find(nums, k, s, n, 0, sum / k);
    }
};