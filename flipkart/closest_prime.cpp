class Solution
{
public:
    int const N = 1e6 + 2;
    vector<int> is_prime;
    void sieve()
    {
        int i = 2;
        while (i * i <= N)
        {
            if (is_prime[i] == 0)
            {
                i++;
                continue;
            }
            int j = 2 * i;
            while (j < N)
            {
                is_prime[j] = 0;
                j += i;
            }
            i++;
        }
    }
    int flag = 1;
    vector<int> closestPrimes(int left, int right)
    {
        if (flag--)
        {
            is_prime = vector<int>(N, 1);
            is_prime[0] = 0;
            is_prime[1] = 0;
            sieve();
        }
        int last = 0;
        int mn = INT_MAX;
        int l = -1, r = -1;
        for (int i = left; i <= right; i++)
        {
            if (is_prime[i])
            {
                if (!last)
                    last = i;
                else
                {
                    if (mn > (i - last))
                    {
                        l = last;
                        r = i;
                        mn = (i - last);
                    }
                    last = i;
                }
            }
        }
        return {l, r};
    }
};