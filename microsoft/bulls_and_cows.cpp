// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    string getHint(string s, string g)
    {
        vector<int> matched(10, 0);
        vector<int> total(10, 0);
        vector<int> shouldpresent(10, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == g[i])
                matched[s[i] - 48]++;
            total[g[i] - 48]++;
            shouldpresent[s[i] - 48]++;
        }

        int b = 0, c = 0;
        for (int i = 0; i <= 9; i++)
            b += matched[i];

        for (int i = 0; i <= 9; i++)
        {
            if (shouldpresent[i] >= total[i])
                c += (total[i] - matched[i]);
            else
                c += (shouldpresent[i] - matched[i]);
        }
        string m = to_string(b);
        string n = to_string(c);
        string ans = m + "A" + n + "B";
        return ans;
    }
};
int main()
{

    return 0;
}
