// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>
#define ll long long
using namespace std;
class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        unordered_map<string, ll> fre;
        unordered_map<string, multiset<pair<ll, string>, greater<pair<ll, string>>>> umap;
        multiset<pair<ll, string>, greater<pair<ll, string>>> st;

        for (int i = 0; i < creators.size(); i++)
        {
            fre[creators[i]] += views[i];
            umap[creators[i]].insert({views[i], ids[i]});
        }

        for (auto p : fre)
            st.insert({p.second, p.first});

        ll a = (*st.begin()).first;
        vector<vector<string>> ans;
        vector<string> v;
        while (!st.empty())
        {
            if ((*st.begin()).first == a)
            {
                ll b = -1;
                multiset<pair<ll, string>, greater<pair<ll, string>>> temp = umap[(*st.begin()).second];
                if (!temp.empty())
                    b = (*temp.begin()).first;
                vector<string> t;
                while (!temp.empty())
                {
                    if ((*temp.begin()).first == b)
                    {
                        t.push_back((*temp.begin()).second);
                        temp.erase(temp.begin());
                    }
                    else
                        break;
                }
                sort(t.begin(), t.end());
                ans.push_back({(*st.begin()).second, t[0]});
                st.erase(st.begin());
            }
            else
                break;
        }
        return ans;
    }
};

int main()
{

    return 0;
}
