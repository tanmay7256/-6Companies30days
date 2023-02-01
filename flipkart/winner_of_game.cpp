class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        deque<int> dq;
        for (int i = 1; i <= n; i++)
            dq.push_back(i);
        int i = 1;
        while (dq.size() != 1)
        {
            if (i != k)
                dq.push_back(dq.front());
            else
                i = 0;
            dq.pop_front();
            i++;
        }
        return dq.front();
    }
};