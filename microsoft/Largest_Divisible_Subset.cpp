// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> umap, visited, factor;
    vector<int> v;
    int mxone;
    pair<int, int> find(long long node)
    {
        if (node > 2 * 1e9 || node > mxone)
            return {0, -1};
        if (visited[node])
            return {visited[node], node};
        int i = 2;
        int mx = 0, k = -1;
        while ((node * i <= mxone))
        {
            if (umap[node * i])
            {
                auto p = find((node * i));
                if (p.first > mx)
                {
                    mx = p.first;
                    k = p.second;
                }
                i++;
            }
            else
            {
                int j = upper_bound(v.begin(), v.end(), node * i) - v.begin();
                if (v[j] / node > i)
                    i = v[j] / node;
                else
                    i++;
            }
        }
        visited[node] = mx + 1, factor[node] = k;
        return {mx + 1, node};
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        v = nums;
        mxone = nums[n - 1];
        unordered_map<int, int> tumap, tvisited, tfactor;
        umap = tumap, visited = tvisited, factor = tfactor;
        for (int i = 0; i < n; i++)
            umap[nums[i]] = 1;

        int mx = 0;
        vector<int> ans;
        int k;
        for (int i = 0; i < n; i++)
        {
            auto p = find(nums[i]);
            if (p.first > mx)
            {
                k = nums[i];
                mx = p.first;
            }
        }
        ans.push_back(k);
        cout << visited[90] << endl;
        while (factor[k] != -1)
        {
            k = factor[k];
            ans.push_back(k);
        }
        return ans;
    }
};
int main()
{

    return 0;
}
