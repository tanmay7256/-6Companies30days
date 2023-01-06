// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums.size());
        int sum = 0, a = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i], a += (i * nums[i]);
        dp[0] = a;
        int mx = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + sum - n * nums[n - i], mx = max(mx, dp[i]);
        }
        return mx;
    }
};
int main()
{

    return 0;
}
