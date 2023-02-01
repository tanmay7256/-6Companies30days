class Solution
{
public:
    string predictPartyVictory(string s)
    {
        int r = 0, d = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
                r++;
            else
                d++;
        }
        int cr = 0, cd = 0;
    start:;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'R')
            {
                if (cr)
                {
                    cr--;
                    s[i] = '.';
                }
                else
                {
                    cd++;
                    d--;
                }
            }
            else if (s[i] == 'D')
            {
                if (cd)
                {
                    cd--;
                    s[i] = '.';
                }
                else
                {
                    cr++;
                    r--;
                }
            }
            if (r == 0 || d == 0)
                break;
        }
        if (d > 0 && r > 0)
            goto start;
        if (r > 0)
            return "Radiant";
        else
            return "Dire";
        return "Radiant";
    }
};