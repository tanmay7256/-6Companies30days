class Solution
{
public:
    int magicalString(int n)
    {
        if (n <= 3)
            return 1;
        int i = 2, j = 3, c = 1, f = 1;
        string s = "122";
        while (s.length() <= n)
        {
            j = s[i] - '0';
            if (f)
            {
                string t(j, '1');
                f = 0;
                int l = s.length();
                s += t;
                c = c + (min(n - l, j));
            }
            else
            {
                string t(j, '2');
                f = 1;
                s += t;
            }
            i++;
        }
        cout << s << endl;
        return c;
    }
};