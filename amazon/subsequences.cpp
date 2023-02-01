#define vs vector<string>
class Solution
{
public:
    unordered_map<string, int> umap;
    string st;
    int find(string &s, int n)
    {
        int j = 0;
        for (int i = 0; i < n && j < s.length(); i++)
        {
            if (st[i] == s[j])
                j++;
        }
        if (j == s.length())
            return 1;
        return -1;
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        st = s;
        int ans = 0;
        for (auto word : words)
            if (!umap[word])
            {
                umap[word] = find(word, s.length());
                if (umap[word] == 1)
                    ans++;
            }
            else
            {
                if (umap[word] == 1)
                    ans++;
            }
        return ans;
    }
};