class Solution
{
public:
    int ans;
    void find(vector<int> &price, vector<vector<int>> &special, vector<int> needs, int oidx, int sum)
    {
        if (oidx >= special.size())
        {
            // cout<<sum<<needs[0]<<endl;
            for (int j = 0; j < needs.size(); j++)
                sum += needs[j] * price[j];
            ans = min(ans, sum);
            return;
        }
        int n = needs.size();
        int i = 0;
        find(price, special, needs, oidx + 1, sum);
        while (1)
        {
            for (int j = 0; j < n; j++)
                if ((needs[j] - special[oidx][j]) >= 0)
                    needs[j] = (needs[j] - special[oidx][j]);
                else
                    goto end;
            sum = sum + special[oidx][n];
            if (sum > ans)
                return;
            find(price, special, needs, oidx + 1, sum);
        }
    end:;
        return;
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        ans = INT_MAX;
        find(price, special, needs, 0, 0);
        return ans;
    }
};