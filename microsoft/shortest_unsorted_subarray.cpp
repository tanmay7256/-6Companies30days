// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> v = nums;
        int n = v.size();
        int a = n;
        for (int i = 1; i < v.size(); i++)
            if (v[i] < v[i - 1])
            {
                a = i;
                break;
            }
        if (a == n)
            return 0;
        int k = v[a], mn = a;
        for (int i = a; i < v.size(); i++)
            if (v[i] < k)
                mn = i;

        // for last
        int b = 0;
        for (int i = n - 2; i >= 0; i--)
            if (v[i] > nums[i + 1])
            {
                b = i;
                break;
            }

        for (int i = b; i >= a - 1; i--)
            if (v[i] > nums[i + 1])
            {
                b = i;
                break;
            }
        return a;
    }
};
int main()
{

    return 0;
}
