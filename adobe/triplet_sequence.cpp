class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for (auto &i : nums)
            if (i <= mn1)
                mn1 = i;
            else if (i <= mn2)
                mn2 = i;
            else
                return 1;
        return 0;
    }
};