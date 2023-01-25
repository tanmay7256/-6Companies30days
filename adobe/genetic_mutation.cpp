class Solution
{
public:
    int ans;
    unordered_map<string, int> umap;
    void find(string sg, string &eg, vector<string> &bank, string s, int k)
    {
        if (sg == eg)
        {
            ans = min(ans, k);
            return;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
                continue;
            string t = bank[i];
            int c = -1, j = 0;
            for (j = 0; j < 8; j++)
                if (sg[j] != t[j])
                {
                    if (c != -1)
                        break;
                    else
                        c = j;
                }
            if (j != 8)
                continue;
            s[i] = '-';
            find(t, eg, bank, s, k + 1);
            s[i] = '.';
        }
        return;
    }
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        ans = INT_MAX;
        string s(bank.size(), '.');
        umap.clear();

        find(startGene, endGene, bank, s, 0);
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};