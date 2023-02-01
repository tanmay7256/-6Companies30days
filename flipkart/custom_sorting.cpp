class Solution
{
public:
    string customSortString(string order, string s)
    {
        map<int, int> unmap;
        vector<char> sans;
        string ans = "";
        for (auto c : s)
            unmap[c]++;
        for (auto c : order)
        {
            if (unmap.find(c) != unmap.end())
            {
                auto x = unmap.find(c);
                int value = x->second;
                vector<char> vs(value, c);
                sans.insert(sans.end(), vs.begin(), vs.end());
                unmap.erase(c);
            }
        }
        for (auto x : unmap)
        {
            int value = x.second;
            vector<char> vs(value, x.first);
            sans.insert(sans.end(), vs.begin(), vs.end());
        }
        for (auto c : sans)
            ans += c;
        return ans;
    }
};