class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        int N = 1e9 + 7;
        vector<long long> v(n + 1 + forget + 2, 0);
        v[1] = 1;
        long long sum = 0, j = 1;
        for (int i = delay + 1; i < forget + 1; i++)
        {
            sum += v[j];
            v[i] = sum % N;
            j++;
        }
        int f = 1;
        for (int i = forget + 1; i <= n + forget; i++)
        {
            sum += v[j];
            sum -= v[f];
            v[i] = sum % N;
            j++;
            f++;
        }
        long long s = 0;

        if (forget > n)
        {
            for (int i = 1; i <= n; i++)
                s += v[i], s %= N;
            return s;
        }

        for (int i = n - forget + 1; i <= n; i++)
        {
            s += v[i], s %= N;
        }

        return s;
    }
};