class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int a = 0;
        if (left.size())
            a = *max_element(left.begin(), left.end());
        int b = n;
        if (right.size())
            b = *min_element(right.begin(), right.end());
        int ans = max(n - b, a);
        return ans;
    }
};