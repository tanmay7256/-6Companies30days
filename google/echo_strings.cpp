// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int distinctEchoSubstrings(string s)
    {
        int n = s.size();
        int ans = 0;
        unordered_map<string, int> umap;
        for (int i = 1; i <= n / 2; i++)
        {
            int k = 0, c = 0;
            for (int j = i; j < n; j++)
            {
                if (s[k] == s[j])
                    c++;
                else
                    c = 0;
                if (c == i)
                {
                    string str = s.substr(k + 1, i);
                    if (!umap[str])
                    {
                        umap[str] = 1;
                        ans++;
                    }
                    c--;
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}
