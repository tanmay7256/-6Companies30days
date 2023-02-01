bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first > b.first)
        return true;
    if (a.first == b.first)
        if (a.second < b.second)
            return true;

    return false;
}
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> umap;
        for (auto x : words)
            umap[x]++;
        vector<pair<int, string>> v;
        for (auto p : umap)
            v.push_back({p.second, p.first});
        sort(v.begin(), v.end(), cmp);
        vector<string> ans;
        int i = 0;
        while (k--)
        {
            ans.push_back(v[i++].second);
        }
        return ans;
    }
};