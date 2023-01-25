#define ll long long
class Solution
{
public:
    string fractionToDecimal(ll n, ll d)
    {
        string ans = "";
        if ((n < 0 ^ d < 0) && n != 0)
            ans += "-";
        n = labs(n), d = labs(d);
        ans += to_string(n / d);
        ll r = n % d;
        if (!r)
            return ans;
        ans += '.';
        unordered_map<int, int> umap;
        while (r)
        {
            if (umap.find(r) != umap.end())
            {
                ans.insert(umap[r], "(");
                ans += ")";
                break;
            }
            umap[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r = r % d;
        }
        return ans;
    }
};