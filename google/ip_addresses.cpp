class Solution
{
public:
    vector<string> ans;
    void find(string s, int st, int k)
    {
        if (k == 0 && (s.length() - st - 1) > 2)
            return;
        if (k == 0)
        {
            if (st < (s.length() - 1) && s[st] == '0')
                return;
            if (st == (s.length() - 3) && stoi(s.substr(st, s.length() - st)) > 255)
                return;
            ans.push_back(s);
            return;
        }
        for (int i = st; (i < (st + 3)) && (i < (s.length() - 1)); i++)
        {
            if (stoi(s.substr(st, i - st + 1)) <= 255 && ((s[st] != '0') || (i == st)))
            {
                string temp = s.substr(0, i + 1) + "." + s.substr(i + 1, s.length() - i - 1);
                find(temp, i + 2, k - 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        ans.clear();
        find(s, 0, 3);
        return ans;
    }
};