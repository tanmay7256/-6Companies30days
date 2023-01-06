// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    map<vector<int>, int> umap;
    void find(int k, int n, set<int> st, vector<int> v)
    {
        if (k < 0 || n < 0 || (st.empty() && (n != 0 || k != 0)))
            return;
        if (k == 0 && n == 0)
        {
            sort(v.begin(), v.end());
            umap[v] = 1;
            return;
        }
        int a = *(st.begin());
        st.erase(a);
        find(k, n, st, v);
        v.push_back(a);
        find(k - 1, n - a, st, v);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        set<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        find(k, n, st, {});
        for (auto p : umap)
        {
            ans.push_back(p.first);
        }
        return ans;
    }
};
int main()
{

    return 0;
}
