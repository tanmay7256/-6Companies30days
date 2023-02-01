#define vii vector<vector<int>>
#define vi vector<int>
class Solution
{
public:
    vii dp;
    int mx = 0;
    int doit(vector<int> &nums1, vector<int> &nums2, int n, int m, int sz1, int sz2)
    {
        if (n == sz1 || m == sz2)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (nums1[n] == nums2[m])
        {
            dp[n][m] = 1 + doit(nums1, nums2, n + 1, m + 1, sz1, sz2);
            mx = max(mx, dp[n][m]);
        }
        else
            dp[n][m] = 0;
        int l = doit(nums1, nums2, n + 1, m, sz1, sz2);
        l = doit(nums1, nums2, n, m + 1, sz1, sz2);

        return dp[n][m];
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        dp = vii(n + 1, vi(m + 1, -1));
        int i = doit(nums1, nums2, 0, 0, n, m);
        return mx;
    }
};