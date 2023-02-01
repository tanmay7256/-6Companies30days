class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> pre(n, 0), suf(n, 0), ans(n, 0);
        // cout<<"jai"<<endl;
        for (int i = 0; i < n; i++)
            pre[i] += nums[i], suf[i] += nums[i];

        for (int i = 1; i < n; i++)
            pre[i] += pre[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suf[i] += suf[i + 1];

        stack<pair<int, int>> stk, sufstk;

        for (int i = 0; i < n; i++)
        {
            int a = nums[i];
            while (!stk.empty())
            {
                auto p = stk.top();
                if (p.first < a)
                    break;
                stk.pop();
            }
            if (!stk.empty())
                ans[i] = -pre[stk.top().second];
            ans[i] += (pre[i] - nums[i]);
            stk.push({nums[i], i});
            // cout<<ans[i]<<endl;
        }
        long long mx = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int a = nums[i];
            while (!sufstk.empty())
            {
                auto p = sufstk.top();
                if (p.first <= a)
                    break;
                sufstk.pop();
            }
            if (!sufstk.empty())
                ans[i] -= suf[sufstk.top().second];
            ans[i] += (suf[i]);
            sufstk.push({nums[i], i});
            // cout<<ans[i]<<" "<<nums[i]*ans[i]<<endl;
            mx = max(mx, nums[i] * ans[i]);
        }
        int N = 1e9 + 7;
        return mx % N;
    }
};