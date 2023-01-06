// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &arr)
    {
        int n = nums.size(), m = arr.size();
        int a = arr[0];
        for (int i = 0; i < m; i++)
        {
            a = __gcd(a, arr[i]);
        }
        sort(nums.begin(), nums.end());
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (a % nums[i] == 0)
                return c;
            c++;
        }
        return -1;
    }
};
int main()
{

    return 0;
}
