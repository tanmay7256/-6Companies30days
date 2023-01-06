// #include<iostream>
#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define umii unordered_map<int, int>

using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int result = 0;
        for (long long i = 5; n / i > 0; i *= 5)
        {
            result += (n / i);
        }
        return result;
    }
};
int main()
{

    return 0;
}
